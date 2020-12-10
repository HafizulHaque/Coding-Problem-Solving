#include<bits/stdc++.h>
using namespace std;

#define mx 100010
int ara[mx],tree[3*mx],tree1[3*mx];

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

void init1(int node,int b,int e)
{
    int left,right,mid;
    if(b==e){
        tree1[node]=ara[b];
        return;
    }
    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    init1(left,b,mid);
    init1(right,mid+1,e);
    tree1[node]=max(tree1[left],tree1[right]);
}

int query(int node,int b,int e,int i,int j)
{
    int right,left,mid,p1,p2;
    if(b>j or e<i)return 1000000000;
    if(b>=i and e<=j){
        return tree[node];
    }
    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    p1=query(left,b,mid,i,j);
    p2=query(right,mid+1,e,i,j);
    return min(p1,p2);
}

int query1(int node,int b,int e,int i,int j)
{
    int right,left,mid,p1,p2;
    if(b>j or e<i)return 0;
    if(b>=i and e<=j){
        return tree1[node];
    }
    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    p1=query1(left,b,mid,i,j);
    p2=query1(right,mid+1,e,i,j);
    return max(p1,p2);
}

int main()
{
    int t,cas=0,a,b,c,n,d;
    cin>>t;
    while(t--){
        scanf("%d %d",&n,&d);

        for(int i=1;i<=n;i++)
            scanf("%d",&ara[i]);
        init(1,1,n);
        init1(1,1,n);

        int v=0;
        for(int i=1;i<=n-d+1;i++){
            a=query(1,1,n,i,i+d-1);
            b=query1(1,1,n,i,i+d-1);
            v=max(v,abs(a-b));
        }
        printf("Case %d: %d\n",++cas,v);
    }
}
