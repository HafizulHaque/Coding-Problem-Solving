#include<bits/stdc++.h>
using namespace std;

#define mx 30010
#define inf 10000000
#define lli long long
int ara[mx],tree[3*mx];

void init(int node,int b,int e)
{
    int left,right,mid;
    if(b==e){
        tree[node]=b;
        return;
    }
    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);
    if(ara[tree[left]]>ara[tree[right]])
        tree[node]=tree[right];
    else tree[node]=tree[left];
}

int query(int node,int b,int e,int i,int j)
{
    int left,right,mid,p1,p2;
    if(b>j or e<i)return inf;
    if(b>=i and e<=j){
        return tree[node];
    }
    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    p1=query(left,b,mid,i,j);
    p2=query(right,mid+1,e,i,j);
    if(p2==inf)return p1;
    if(p1==inf)return p2;
    if(ara[p2]>=ara[p1])return p1;
    else if(ara[p2]<=ara[p1])return p2;
}

int res(int b,int e,int n)
{
    if(b>e)return 0;
    if(b==e)return tree[b];

    int mid=query(1,1,n,b,e);
    int x=res(b,mid-1,n);
    int y=res(mid+1,e,n);

    //cout<<b<<' '<<e<<' '<<x<<' '<<y<<' ';
    int ans=max(max(x,y),ara[mid]*(e-b+1));
   // cout<<ans<<endl;
    return ans;
}

int main()
{
    int t,cas=0,a,b,n;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&ara[i]);
        init(1,1,n);
        printf("Case %d: %d\n",++cas,res(1,n,n));
    }
}

