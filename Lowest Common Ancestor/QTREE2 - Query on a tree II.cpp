#include<bits/stdc++.h>
using namespace std;

#define pii pair <int,int>
#define mx 10010
int dist[mx],level[mx],par[mx],vis[mx],sparse[mx][15],n;
vector<pii>edges[mx];

void dfs(int node,int p)
{
    for(int i=0;i<edges[node].size();i++){
        int v=edges[node][i].first;
        int x=edges[node][i].second;
        if(vis[v]==1)continue;
        vis[v]=1;
        par[v]=node;
        level[v]=level[node]+1;
        dist[v]=dist[node]+x;
       // cout<<"V"<<' '<<v<<' '<<par[v]<<' '<<level[v]<<' '<<dist[v]<<endl;
        dfs(v,node);
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

int child(int u,int k)
{
    int m=log2(k);
    for(int i=m;i>=0;i--){
        if(k-(1<<i)>=0){
            u=sparse[u][i];
            k=k-(1<<i);
        }
    }
    return u;
}

void clr()
{
    for(int i=0;i<mx;i++)edges[i].clear();
    memset(dist,0,sizeof dist);
    memset(level,0,sizeof level);
    memset(par,-1,sizeof par);
    memset(sparse,-1,sizeof sparse);
    memset(vis,0,sizeof(vis));
}

int main()
{
    int t;
    cin>>t;
    while(t--){
        clr();
        int u,v,c,k;
        scanf("%d",&n);

        for(int i=1;i<n;i++){
            scanf("%d %d %d",&u,&v,&c);
            edges[u].push_back(pii(v,c));
            edges[v].push_back(pii(u,c));
        }

        vis[1]=1;
        dfs(1,0);
        init();
        while(1){
            string s1;
            cin>>s1;
            if(s1=="DONE")break;
            if(s1=="DIST"){
                scanf("%d %d",&u,&v);
                int x=query(u,v);
                cout<<dist[u]+dist[v]-2*dist[x]<<endl;
            }
            else{
                scanf("%d %d %d",&u,&v,&k);
                int x=query(u,v);
                int d=level[u]+level[v]-2*level[x]+1;
                if(level[u]-level[x]+1>=k){
                    cout<<child(u,--k)<<endl;
                }
                else{
                    d=d-k;
                    cout<<child(v,d)<<endl;
                }
            }
        }
        cout<<endl;
    }
}
