#include<bits/stdc++.h>
using namespace std;

#define lli long long
#define mx 100010
#define pii pair<int,lli>
int n,level[mx],par[mx],vis[mx],sparse[mx][20];
lli dist[mx];
vector<pii>edges[mx];

void dfs(int node)
{
    vis[node]=1;
    for(int i=0;i<edges[node].size();i++){
        int v=edges[node][i].first;
        lli x=edges[node][i].second;
        if(vis[v]==1)continue;
        par[v]=node;
        level[v]=level[node]+1;
        dist[v]=dist[node]+x;
       // cout<<"V "<<v<<' '<<par[v]<<' '<<level[v]<<' '<<dist[v]<<endl;
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

int query(int p,int q)
{
    if(level[p]<level[q])swap(p,q);
    int m=log2(level[p]);

    for(int i=m;i>=0;i--){
        if(level[p]-(1<<i)>=level[q])p=sparse[p][i];
    }
    if(p==q)return p;
    m=log2(level[p]);

    for(int i=m;i>=0;i--){
        if(sparse[p][i]!=-1 and sparse[p][i]!=sparse[q][i]){
            p=sparse[p][i];
            q=sparse[q][i];
        }
    }
    return par[p];
}

void clr()
{
    memset(vis,0,sizeof vis);
    memset(level,0,sizeof level);
    memset(par,-1,sizeof par);
    memset(dist,0,sizeof dist);
    for(int i=0;i<mx;i++)edges[i].clear();
}
int main()
{
    while(cin>>n){
        if(n==0)break;
        lli c,d;
        int u,v,l;
        clr();
        for(int i=1;i<n;i++){
            scanf("%d %lld",&u,&c);
            v=i+1;u++;
            edges[v].push_back(pii(u,c));
            edges[u].push_back(pii(v,c));
        }
        dfs(1); init();
        scanf("%d",&l);
        for(int i=1;i<=l;i++){
            scanf("%d %d",&u,&v);
            u++,v++;
            int x=query(u,v);
            d=dist[u]+dist[v]-2*dist[x];
            printf("%lld",d);
            if(i==l)printf("\n");
            else printf(" ");
        }
    }
}
