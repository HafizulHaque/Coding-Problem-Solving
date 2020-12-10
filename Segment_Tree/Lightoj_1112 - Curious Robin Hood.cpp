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
    tree[node]=tree[left]+tree[right];
}

int query(int node,int b,int e,int i,int j)
{
    int left,right,mid,p1,p2;
    if(b>j or e<i)return 0;
    if(b>=i and e<=j)return tree[node];
    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    p1=query(left,b,mid,i,j);
    p2=query(right,mid+1,e,i,j);
    return p1+p2;
}

void update(int node,int b,int e,int i,int value,int f)
{
    int left,right,mid;
    if(b>i or e<i)return;
    if(b==e){
        if(f==1)tree[node]+=value;
        else tree[node]=value;
        return;
    }
    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    update(left,b,mid,i,value,f);
    update(right,mid+1,e,i,value,f);
    tree[node]=tree[left]+tree[right];
}
int main()
{
    int t,cas=0,n,q,x,a,b,v;
    scanf("%d",&t);

    while(t--){
        scanf("%d %d",&n,&q);

        for(int i=1;i<=n;i++)
            scanf("%d",&ara[i]);

        init(1,1,n);
        printf("Case %d:\n",++cas);

        while(q--){
            scanf("%d",&x);
            if(x==1){
                scanf("%d",&a);
                v=query(1,1,n,a+1,a+1);
                update(1,1,n,a+1,0,0);
                printf("%d\n",v);
            }
            else if(x==2){
                scanf("%d %d",&a,&b);
                update(1,1,n,a+1,b,1);
            }
            else{
                scanf("%d %d",&a,&b);
                v=query(1,1,n,a+1,b+1);
                printf("%d\n",v);
            }
        }
    }
}
