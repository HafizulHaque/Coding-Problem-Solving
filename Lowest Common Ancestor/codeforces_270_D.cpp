#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,long long>
#define lli long long
#define mx 2005
lli dist[mx][mx],finaldist[mx][mx],cost[mx];
int n,pr[mx],vis[mx],level[mx],par[mx],sparse[mx][15];
vector<pii>edges[mx];

struct vertex
{
    int u,v,w;
    bool operator <(const vertex &p)const
    {
        return w<p.w;
    }
};
vector<vertex>medges;

void dfs(int node)
{
    vis[node]=1;
    for(int i=0;i<edges[node].size();i++){
        int v=edges[node][i].first;
        int x=edges[node][i].second;
        if(vis[v]==1)continue;
        par[v]=node;
        level[v]=level[node]+1;
        cost[v]=cost[node]+x;
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

int find_r(int r)
{
    if(pr[r]==r)return r;
    else{
        pr[r]=find_r(pr[r]);
        return pr[r];
    }
}

int mst()
{
    sort(medges.begin(),medges.end());
    for(int i=1;i<=n;i++)pr[i]=i;
    int count=0;

    for(int i=0;i<(int)medges.size();i++){
        int u=find_r(medges[i].u);
        int v=find_r(medges[i].v);

        if(u!=v){
            pr[u]=v; count++;
            int x,y,z;
            x=medges[i].u,y=medges[i].v,z=medges[i].w;
            edges[x].push_back(pii(y,z));
            edges[y].push_back(pii(x,z));
            if(count==n-1)break;

        }
    }
}
int main()
{
    cin>>n;
    memset(finaldist,-1,sizeof finaldist);

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)finaldist[i][j]=0;
            scanf("%lld",&dist[i][j]);
        }
    }

    for(int i=1;i<=n;i++){
        vertex get;
        for(int j=i+1;j<=n;j++){
            if(dist[i][j]!=0){
                get.u=i;get.v=j;get.w=dist[i][j];
                medges.push_back(get);
            }
        }
    }
    mst(); dfs(1); init();

    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(dist[i][j]==0)continue;
            int x=query(i,j);
            lli d=cost[i]+cost[j]-2*cost[x];
            finaldist[i][j]=d;
            finaldist[j][i]=d;
        }
    }

    for(int i=1;i<=n;i++){
        for(int j=i;j<=n;j++){
            if(dist[i][j]!=finaldist[i][j]){
                cout<<"NO"<<endl;
                return 0;
            }
        }
    }
    cout<<"YES"<<endl;
}
