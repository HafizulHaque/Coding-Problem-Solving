#include<bits/stdc++.h>
using namespace std;

#define mx 510
int ara[mx][mx],tree[mx][3*mx];

void init(int node,int b,int e,int i)
{
    int left,right,mid;
    if(b==e){
        tree[i][node]=ara[i][b];
        return;
    }
    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    init(left,b,mid,i);
    init(right,mid+1,e,i);
    tree[i][node]=max(tree[i][left],tree[i][right]);
    return;
}

int query(int node,int b,int e,int i,int j,int x)
{
    int left,right,mid,p1,p2;
    if(i>e or b>j)return 0;
    if(b>=i and e<=j)return tree[x][node];

    left=2*node;
    right=left+1;
    mid=(b+e)/2;

    p1=query(left,b,mid,i,j,x);
    p2=query(right,mid+1,e,i,j,x);
    return max(p1,p2);
}

int main()
{
    int t,cs=0,n,q,u,v,s,e;
    scanf("%d",&t);
    while(t--){
        scanf("%d %d",&n,&q);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                scanf("%d",&ara[i][j]);

        for(int i=1;i<=n;i++)
            init(1,1,n,i);

        printf("Case %d:\n",++cs);
        while(q--){
            scanf("%d %d %d",&u,&v,&s);

            int z;
            int mxx=0;
            for(int i=u;i<u+s;i++){
                z=query(1,1,n,v,v+s-1,i);
                //cout<<i<<' '<<v<<' '<<v+s-1<<' '<<z<<endl;
                mxx=max(mxx,z);
            }
            printf("%d\n",mxx);
        }
    }
}
