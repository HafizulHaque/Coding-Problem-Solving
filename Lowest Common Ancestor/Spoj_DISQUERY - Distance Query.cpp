#include<bits/stdc++.h>
using namespace std;

#define mx 100010
#define pii pair<int,int>
int n,level[mx],cost[mx],par[mx],vis[mx],sparse[mx][20],finalmax[mx][20],finalmin[mx][20];
vector<pii>edges[mx];

void dfs(int node)
{
    vis[node]=1;
    for(int i=0;i<edges[node].size();i++){
        int v=edges[node][i].first;
        int x=edges[node][i].second;
        if(vis[v]==1)continue;
        par[v]=node;
        level[v]=level[node]+1;
        cost[v]=x;
        //cout<<"V "<<v<<' '<<par[v]<<' '<<cost[v]<<' '<<level[v]<<endl;
        dfs(v);
    }
}

void init()
{
    memset(sparse,-1,sizeof sparse);

    for(int i=1;i<=n;i++){
        sparse[i][0]=par[i];
        finalmax[i][0]=cost[i];
        finalmin[i][0]=cost[i];
    }

    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i<=n;i++){
            if(sparse[i][j-1]!=-1){
                sparse[i][j]=sparse[sparse[i][j-1]][j-1];
                finalmax[i][j]=max(finalmax[i][j-1], finalmax[sparse[i][j-1]][j-1]);
                finalmin[i][j]=min(finalmin[i][j-1], finalmin[sparse[i][j-1]][j-1]);
            }
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
   // cout<<u<<' '<<k<<endl;
    int mxx=0;
    int m=log2(k);
    for(int i=m;i>=0;i--){
        if(k-(1<<i)>=0){
            mxx=max(mxx,finalmax[u][i]);
            u=sparse[u][i];
            k=k-(1<<i);
        }
    }
    return mxx;
}

int child1(int u,int k)
{
    //cout<<u<<' '<<k<<endl;
    int mn=1234567;
    int m=log2(k);
    for(int i=m;i>=0;i--){
        if(k-(1<<i)>=0){
            mn=min(mn,finalmin[u][i]);
            u=sparse[u][i];
            k=k-(1<<i);
        }
    }
    return mn;
}
void clr()
{
    memset(level,0,sizeof level);
    memset(vis,0,sizeof vis);
    memset(cost,0,sizeof cost);
    memset(finalmax,0,sizeof finalmax);
    memset(finalmin,0, sizeof finalmin);
    memset(par,-1,sizeof par);
    for(int i=0;i<mx;i++)edges[i].clear();
}
int main()
{
    while(cin>>n){
        int u,q,v,w,x,a,b,c,d;
        clr();
        for(int i=1;i<n;i++){
            scanf("%d %d %d",&u,&v,&w);
            edges[u].push_back(pii(v,w));
            edges[v].push_back(pii(u,w));
        }
        dfs(1);init();
        scanf("%d",&q);

        while(q--){
            scanf("%d %d",&u,&v);
            x=query(u,v);
           // cout<<x<<endl;
            a=child(u,level[u]-level[x]);
            b=child(v,level[v]-level[x]);
            c=child1(u,level[u]-level[x]);
            d=child1(v,level[v]-level[x]);
           // cout<<a<<' '<<b<<' '<<c<<' '<<d<<endl;
            printf("%d %d\n",min(c,d),max(a,b));
        }
    }
}

