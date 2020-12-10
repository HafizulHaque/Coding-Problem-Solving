#include<bits/stdc++.h>
using namespace std;

#define mx 100010
#define lli long long
#define pii pair<int,int>
int n,vis[mx],par[mx],cost[mx],level[mx],sparse[mx][20];
vector<pii>edges[mx];

int dfs(int node)
{
    vis[node]=1;
    for(int i=0;i<edges[node].size();i++){
        int v=edges[node][i].first;
        int x=edges[node][i].second;
        if(vis[v]==1)continue;
        par[v]=node;
        level[v]=level[node]+1;
        cost[v]=x;
       // cout<<"V "<<v<<' '<<par[v]<<' '<<level[v]<<' '<<cost[v]<<endl;
        dfs(v);
    }
}
void init()
{
    memset(sparse,-1,sizeof sparse);

    for(int i=1;i<=n;i++)sparse[i][0]=par[i];

    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i<=n;i++){
                if(sparse[i][j-1]!=-1)sparse[i][j]=sparse[sparse[i][j-1]][j-1];
        }
    }
}
int query(int p,int v)
{
    int m=log2(level[p]);
    for(int i=m;i>=0;i--){
        if(level[p]-(1<<i)>=0){
            int x=sparse[p][i];
           // cout<<x<<' '<<cost[x]<<' '<<v<<endl;
            if(cost[x]>=v)p=x;
        }
    }
    printf("%d\n",p-1);
    return p;
}
void clr()
{
    memset(vis,0,sizeof vis);
    memset(par,-1,sizeof par);
    memset(cost,0,sizeof cost);
    memset(level,0,sizeof level);
    for(int i=0;i<mx;i++)edges[i].clear();
}
int main()
{
    int t,cs=0;
    scanf("%d",&t);
    while(t--){
        int u,v,w,q;
        scanf("%d %d",&n,&q);
        clr();
        for(int i=2;i<=n;i++){
            scanf("%d %d",&u,&w);
            v=u+1;
            edges[i].push_back(pii(v,w));
            edges[v].push_back(pii(i,w));
        }
        cost[1]=1;
        dfs(1);init();
        printf("Case %d:\n",++cs);
        while(q--){
            scanf("%d %d",&u,&v);
            u++;
            query(u,v);
        }
    }
}
