#include<bits/stdc++.h>
using namespace std;

#define mx 100010

struct st
{
    int a[5],prop;
}tree[6*mx];

void init(int node,int b,int e)
{
    int left,right,mid;
    if(b==e){
        tree[node].a[0]=1;
        return;
    }
    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    init(left,b,mid);
    init(right,mid+1,e);
    tree[node].a[0]=tree[left].a[0]+tree[right].a[0];
    tree[node].a[1]=0;tree[node].a[2]=0;tree[node].prop=0;
    return;
}

void update(int node,int b,int e,int i,int j)
{
    int left,right,mid;

    if(b>j or e<i)return;
    if(b>=i and e<=j){
      // cout<<node<<' '<<b<<' '<<e<<' '<<i<<' '<<j<<endl;
        tree[node].prop+=1;
        swap(tree[node].a[2],tree[node].a[1]);
        swap(tree[node].a[1],tree[node].a[0]);
        return;
    }

    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    update(left,b,mid,i,j);
    update(right,mid+1,e,i,j);
    tree[node].a[0]=tree[right].a[0]+tree[left].a[0];
    tree[node].a[1]=tree[right].a[1]+tree[left].a[1];
    tree[node].a[2]=tree[right].a[2]+tree[left].a[2];
    int x=tree[node].prop%3;
    if(x>=1){
        swap(tree[node].a[2],tree[node].a[1]);
        swap(tree[node].a[1],tree[node].a[0]);
    }
    if(x>1){
        swap(tree[node].a[2],tree[node].a[1]);
        swap(tree[node].a[1],tree[node].a[0]);
    }
    return;
}

int query(int node,int b,int e,int i,int j,int carry)
{
    int left,right,mid;
    if(b>j or e<i)return 0;
    if(b>=i and e<=j){
        // cout<<node<<' '<<b<<' '<<e<<' '<<i<<' '<<j<<endl;
        int x=(carry%3);
        x=3-x;x%=3;
        //cout<<node<<' '<<x<<' '<<tree[node].a[x]<<endl;
        return tree[node].a[x];
    }

    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    int p1=query(left,b,mid,i,j,carry+tree[node].prop);
    int p2=query(right,mid+1,e,i,j,carry+tree[node].prop);
    return p1+p2;
}
int main()
{
    int t,cs=0,n,q,a,u,v;
        scanf("%d %d",&n,&q);
        memset(tree,0, sizeof tree);
        init(1,1,n);
        printf("Case %d:\n",++cs);
        while(q--){
            scanf("%d %d %d",&a,&u,&v);
            u++,v++;
            if(a==0)update(1,1,n,u,v);
            else printf("%d\n",query(1,1,n,u,v,0));
        }
}
