#include<bits/stdc++.h>
using namespace std;

#define mx 100010
#define pii pair <int,int>
#define lli long long
long long ara[mx],tree[4*mx],que[mx];

void init(int node,int b,int e)
{
    int left,right,mid;
    if(b==e){
        tree[node]=ara[b];
        return;
    }

    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);

    tree[node]=tree[left]+tree[right];
    return;
}

void update(int node,int b,int e,int i,int j,int value)
{
    int left,right,mid;
    if(i>e or b>j)return;
    if(b>=i and e<=j){
        tree[node]=value;
        return;
    }

    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    update(left,b,mid,i,j,value);
    update(right,mid+1,e,i,j,value);
    tree[node]=tree[left]+tree[right];
}

lli query(int node,int b,int e,int i,int j)
{
    int left,right,mid;

    if(i>e or b>j)return 0;
    if(b>=i and e<=j){
         return tree[node];
    }

    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    lli p1=query(left,b,mid,i,j);
    lli p2=query(right,mid+1,e,i,j);

    return p1+p2;
}

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)cin>>ara[i];
    for(int i=1;i<=n;i++)cin>>que[i];

    init(1,1,n);

    vector<int>v;
    for(int i=1;i<=n;i++){
        v.push_back(que[i]);
        sort(v.begin(),v.end());
        update(1,1,n,que[i],que[i],0);
        lli mxx=0;
        int x=1,y=n;
        for(int j=0;j<v.size();j++){
            y=v[j]-1;
            if(x<=y){
                lli a=query(1,1,n,x,y);
                mxx=max(mxx,a);
            }
            x=v[j]+1;
        }
        y=n;
        if(x<=y){
            lli a=query(1,1,n,x,y);
            mxx=max(mxx,a);
        }
        cout<<mxx<<endl;
    }
}


