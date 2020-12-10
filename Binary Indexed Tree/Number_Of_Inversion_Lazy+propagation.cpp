#include<bits/stdc++.h>
using namespace std;

#define mx 200010
int ara[mx],ara1[mx],n;
map<int,int>my;

struct st
{
    int prop,sum;
}tree[3*mx];

int query(int node,int b,int e,int i,int j,int carry)
{
    int left,right,mid,p1,p2;

    if(b>j or e<i)return 0;
    if(b>=i and e<=j){
        return tree[node].sum+(e-b+1)*carry;
    }

    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    p1=query(left,b,mid,i,j,carry+tree[node].prop);
    p2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return p1+p2;
}

void update(int node,int b,int e,int i,int j,int x)
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
    tree[node].sum=tree[left].sum+tree[right].sum+tree[node].prop*(e-b+1);
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
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        clr();
        for(int i=1;i<=n;i++){
            scanf("%d",&ara1[i]);
            ara[i]=ara1[i];
        }

        sort(ara1+1,ara1+n+1);
        for(int i=1;i<=n;i++) my[ara1[i]]=i;
        for(int i=1;i<=n;i++) ara[i]=my[ara[i]];

        long long count=0;

        for(int i=n;i>=1;i--){
            int x=ara[i];
            count+=query(1,1,n,x,x,0);
            update(1,1,n,x+1,n,1);
        }
        cout<<count<<endl;
    }
}
