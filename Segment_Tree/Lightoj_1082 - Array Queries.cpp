#include<bits/stdc++.h>
using namespace std;

#define mx 100010
int ara[mx],tree[3*mx];

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
    tree[node]=min(tree[left],tree[right]);
}

int query(int node,int b,int e,int i,int j)
{
    int left,right,mid,p1,p2;
    if(b>j or e<i)return 100010;
    if(b>=i and e<=j)return tree[node];

    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    p1=query(left,b,mid,i,j);
    p2=query(right,mid+1,e,i,j);
    return min(p1,p2);
}

int main()
{
    int t,cas=0,a,b,x,n,q;
    scanf("%d",&t);
    while(t--)
    {
        scanf(" %d %d",&n,&q);

        for(int i=1;i<=n;i++)
            scanf("%d",&ara[i]);
        init(1,1,n);

        printf("Case %d:\n",++cas);
        while(q--){
            scanf("%d %d",&a,&b);
            x=query(1,1,n,a,b);
            printf("%d\n",x);
        }
    }
}
