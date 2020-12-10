#include<bits/stdc++.h>
using namespace std;

#define mx 100010
#define mod 1000000007
#define lli long long
lli ara[mx],ara1[mx];
map<lli,int>my;

struct st
{
    lli sum,prop;
}tree[3*mx];

void init(int node,int b,int e)
{
    int left,right,mid;
    if(b==e){
        tree[node].sum=1;
        tree[node].prop=0;
        return;
    }

    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].sum=tree[left].sum+tree[right].sum;
}

void update(int node,int b,int e,int i,int j,lli x)
{
    int left,right,mid;
    if(b>j or e<i)return;
    if(b>=i and e<=j){
        tree[node].sum+=(e-b+1)*x;
        tree[node].prop+=x;
        return;
    }

    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    update(left,b,mid,i,j,x);
    update(right,mid+1,e,i,j,x);
    tree[node].sum=tree[left].sum+tree[right].sum+(e-b+1)*tree[node].prop;
}

lli query(int node,int b,int e,int i,int j,lli carry)
{
    int left,right,mid;
    lli p1,p2;
    if(b>j or e<i)return 0;
    if(b>=i and e<=j){
        return tree[node].sum+(e-b+1)*carry;
    }

    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    p1=query(left,b,mid,i,j,carry+tree[node].prop)%mod;
    p2=query(right,mid+1,e,i,j,carry+tree[node].prop)%mod;
    return (p1+p2)%mod;
}
void clr()
{
    memset(ara,0,sizeof(ara));
    memset(ara1,0,sizeof(ara1));
    memset(tree,0,sizeof(tree));
    my.clear();
}
int main()
{
    int t,n,cs=0;
    cin>>t;

    while(t--){
        scanf("%d",&n);

        for(int i=1;i<=n;i++){
            scanf("%lld",&ara1[i]);
            ara[i]=ara1[i];
        }

        sort(ara1+1,ara1+n+1);
        int x=1;
        for(int i=1;i<=n;i++) if(my[ara1[i]]==0)my[ara1[i]]=x++;
        for(int i=1;i<=n;i++)ara[i]=my[ara[i]];
        init(1,1,x);
        lli count=0,z;

        for(int i=1;i<=n;i++){
            z=query(1,1,x,ara[i],ara[i],0);
            z=z%mod;
            count=((count%mod)+z)%mod;
            update(1,1,x,ara[i]+1,x,z);
        }

        printf("Case %d: %lld\n",++cs,count);
        clr();
    }
}

