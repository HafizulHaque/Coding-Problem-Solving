#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define mx 50010
int n,m,pr[mx],level[mx],par[mx],vis[mx],sparse[mx][20],cost[mx],finalmax[mx][20];
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
            pr[u]=v;
            count++;
            int x,y,z;
            x=medges[i].u;y=medges[i].v;z=medges[i].w;
           // cout<<"m "<<x<<' '<<y<<' '<<z<<endl;
            edges[x].push_back(pii(y,z));
            edges[y].push_back(pii(x,z));
            if(count==n-1)break;
        }
    }
}

void dfs(int node)
{
    vis[node]=1;
    for(int i=0;i<edges[node].size();i++){
        int v=edges[node][i].first;
        int x=edges[node][i].second;
        if(vis[v]==1)continue;
        par[v]=node;
        cost[v]=x;
        level[v]=level[node]+1;
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
    }

    for(int j=1;(1<<j)<=n;j++){
        for(int i=1;i<=n;i++){
            if(sparse[i][j-1]!=-1){
                sparse[i][j]=sparse[sparse[i][j-1]][j-1];
                finalmax[i][j]=max(finalmax[i][j-1], finalmax[sparse[i][j-1]][j-1]);
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
    int mxx=0;
    int m=log2(k);
    //cout<<u<<' '<<mxx<<' '<<k<<endl;
    for(int i=m;i>=0;i--){
        if(k-(1<<i)>=0){
            mxx=max(mxx,finalmax[u][i]);
            u=sparse[u][i];
            k=k-(1<<i);
        }
    }
    return mxx;
}
void clr()
{
    memset(pr,0,sizeof pr);
    memset(par,-1,sizeof par);
    memset(level,0,sizeof level);
    memset(vis,0,sizeof vis);
    memset(cost,0,sizeof cost);
    memset(sparse,-1,sizeof sparse);
    memset(finalmax,0,sizeof finalmax);
    for(int i=0;i<mx;i++)edges[i].clear();
    medges.clear();

}
int main()
{
    int t,cs=0;
    scanf("%d",&t);
    while(t--){
        int u,v,w,q,k,x,y,z;
        scanf("%d %d",&n,&m);
        clr();
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&u,&v,&w);
            vertex get;
            get.u=u;get.v=v;get.w=w;
            medges.push_back(get);
        }
        mst();
        dfs(1);init();
        scanf("%d",&q);

        printf("Case %d:\n",++cs);
        while(q--){
            scanf("%d %d",&u,&v);
            x=query(u,v);y=0;z=0;
            //cout<<x<<endl;
            k=level[u]-level[x];
            y=child(u,k);
            k=level[v]-level[x];
            z=child(v,k);
            printf("%d\n",max(y,z));
        }
    }
}
