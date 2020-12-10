#include<bits/stdc++.h>
using namespace std;

#define mx 100010
int ara[mx],n;
struct st
{
    int maxi,smaxi;
}tree[3*mx];

void init(int node,int b,int e)
{
    int left,right,mid;
    if(b==e){
          //  cout<<node<<' '<<ara[b]<<endl;
        tree[node].maxi=ara[b];
        tree[node].smaxi=0;
        return;
    }

    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);

    vector<int>v;
    int w,x,y,z;
    w=tree[left].maxi,x=tree[left].smaxi,y=tree[right].maxi,z=tree[right].smaxi;
   // cout<<w<<' '<<x<<' '<<y<<' '<<z<<endl;
    v.push_back(w);v.push_back(x);v.push_back(y);v.push_back(z);
    sort(v.begin(),v.end());
   // cout<<"node "<<node<<' '<<v[2]<<' '<<v[3]<<endl;
    tree[node].maxi=v[3];
    tree[node].smaxi=v[2];
    return;
}

st query(int node,int b,int e,int i,int j)
{
    int left,right,mid;

    if(i>e or b>j){
        st a;a.maxi=0;a.smaxi=0;
        return a;
    }
    if(b>=i and e<=j)return tree[node];

    left=2*node;
    right=left+1;
    mid=(b+e)/2;
    st p1,p2,f;

    p1=query(left,b,mid,i,j);
    p2=query(right,mid+1,e,i,j);

    int w,x,y,z;
    vector<int>v;
    w=p1.maxi,x=p1.smaxi;y=p2.maxi;z=p2.smaxi;
    v.push_back(w);v.push_back(x);v.push_back(y);v.push_back(z);
    sort(v.begin(),v.end());
    f.maxi=v[3];
    f.smaxi=v[2];
    return f;
}

void update(int node,int b,int e,int i,int value)
{
    int left,right,mid;

    if(i>e or i<b)return;
    if(b>=i and e<=i){
        tree[node].maxi=value;
        tree[node].smaxi=0;
        return;
    }
    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    update(left,b,mid,i,value);
    update(right,mid+1,e,i,value);

    vector<int>v;
    int w,x,y,z;
    w=tree[left].maxi,x=tree[left].smaxi,y=tree[right].maxi,z=tree[right].smaxi;
   // cout<<w<<' '<<x<<' '<<y<<' '<<z<<endl;
    v.push_back(w);v.push_back(x);v.push_back(y);v.push_back(z);
    sort(v.begin(),v.end());
  //  cout<<"node "<<node<<' '<<v[2]<<' '<<v[3]<<endl;
    tree[node].maxi=v[3];
    tree[node].smaxi=v[2];
    return;
}
int main()
{
    int q,x,y;
    scanf("%d",&n);

    for(int i=1;i<=n;i++){
        scanf("%d",&ara[i]);
    }
    init(1,1,n);
    scanf("%d",&q);
    char ch;
    while(q--){
        getchar();
        scanf("%c",&ch);
        if(ch=='Q'){
            scanf("%d %d",&x,&y);
            st a=query(1,1,n,x,y);
            printf("%d\n",a.maxi+a.smaxi);
            //cout<<a.maxi<<' '<<a.smaxi<<endl;
        }
        else{
            scanf("%d %d",&x,&y);
            update(1,1,n,x,y);
        }
    }

}
