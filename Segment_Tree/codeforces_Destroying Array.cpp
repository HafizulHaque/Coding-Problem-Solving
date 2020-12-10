#include<bits/stdc++.h>
using namespace std;

#define mx 100010
#define pii pair <int,int>
int ara[mx],tree[4*mx],que[mx];
vector<pii>fquery;

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
    if(i>e or b<j)return;

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

int main()
{
    int n;
    cin>>n;

    for(int i=1;i<=n;i++)cin>>ara[i];
    for(int i=1;i<=n;i++)cin>>que[i];

 //   init(1,1,n);

    vector<int>v;
    for(int i=1;i<=n;i++){
        v.push_back(que[i]);
        sort(v.begin(),v.end());

        int x,y;
        for(int j=0;j<v.size();j++){
                cout<<v[j]<<endl;
            if(j==0 and v.size()==1){
                x=1;
                y=v[j]-1;
                if(x<=y)fquery.push_back(pii(x,y));
                x=v[j]+1;
                y=n;
                if(x<=y)fquery.push_back(pii(x,y));
            }
            else if(j==0){
                x=1;
            }
            else if(j==v.size()-1){
                x=v[j]+1;
                y=n;
                if(x<=y)fquery.push_back(pii(x,y));
            }
            else{
                y=v[j+1]-1;
                if(x<=y)fquery.push_back(pii(x,y));
            }
            x=y;
        }
        cout<<' '<<x<<' '<<y<<endl;
    }

    for(int i=0;i<fquery.size();i++){
        pii a=fquery[i];
        int x,y;
        x=a.first,y=a.second;
        cout<<x<<' '<<y<<endl;
    }
}

