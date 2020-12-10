#include<bits/stdc++.h>
using namespace std;
#define mm 30010
vector<int>edges[mm];
vector<int>value[mm];
int vis[mm];
int dis[mm];
int u,v,w,n;
long long ans;

int bfs(int src)
{
    queue<int>q;
    q.push(src);
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));

    vis[src]=1;
    dis[src]=0;
    long long num=0,max=0;
    int n;

    while(!q.empty())
    {
        int u=q.front(); q.pop();

        for(int i=0; i<edges[u].size();i++){
            int v=edges[u][i];
            if(!vis[v]){
                dis[v]+=dis[u]+value[u][i];
                if(dis[v]>max){
                    max=dis[v];
                    n=v;
                }
                vis[v]=1;
                q.push(v);
            }
        }
    }
    return n;
}

int bfs1(int src)
{
    queue<int>q;
    q.push(src);
    memset(vis,0,sizeof(vis));
    memset(dis,0,sizeof(dis));

    vis[src]=1;
    dis[src]=0;
    long long num=0,max=0;
    int n;

    while(!q.empty())
    {
        int u=q.front(); q.pop();

        for(int i=0; i<edges[u].size();i++){
            int v=edges[u][i];
            if(!vis[v]){
                dis[v]+=dis[u]+value[u][i];
                if(dis[v]>max){
                    max=dis[v];
                    n=v;
                }
                vis[v]=1;
                q.push(v);
            }
        }
    }
    return max;
}
int main()
{
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        for(int i=1;i<n;i++){
            scanf("%d%d%d",&u,&v,&w);
            edges[u].push_back(v);
            edges[v].push_back(u);
            value[u].push_back(w);
            value[v].push_back(w);
        }
        int x=bfs(0);
        long long y=bfs1(x);
        printf("Case %d: %lld\n",++cas,y);
        for(int i=0;i<mm;i++){
            edges[i].clear();
            value[i].clear();
        }
    }

}
