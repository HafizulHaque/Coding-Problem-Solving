#include<bits/stdc++.h>
using namespace std;
#define mm 110

vector<int>edges[mm];
int source[mm],destiny[mm];
int s,d;

int bfs(int src)
{
    int level[mm],vis[mm];
    memset(level,0,sizeof(level));
    memset(vis,0,sizeof(vis));
    queue<int>q;
    q.push(src);

    level[src]=0;
    vis[src]=1;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
            if(v==s){
                source[src]=level[u]+1;
                vis[v]=1;
                while(!q.empty()){
                    q.pop();
                }
                break;
            }
            if(vis[v]==0){
                level[v]=level[u]+1;
                vis[v]=1;
                q.push(v);
            }
        }
    }
}

int bfs1(int src)
{
    queue<int>q;
    q.push(src);

    int level[mm],vis[mm],flag=0;
    memset(level,0,sizeof(level));
    memset(vis,0,sizeof(vis));

    level[src]=0;
    vis[src]=1;
    while(!q.empty())
    {
        int u=q.front();q.pop();
        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
            if(v==d){
                destiny[src]=level[u]+1;
                vis[v]=1;
                while(!q.empty()){
                    q.pop();
                }
                break;
            }

            if(vis[v]==0){
                level[v]=level[u]+1;
                vis[v]=1;
                q.push(v);
            }
        }
    }
}

int main()
{
    int t,cas=0;
    scanf("%d",&t);

    while(t--){
        int n,r,u,v;
        scanf("%d%d",&n,&r);

        for(int i=1;i<=r;i++){
            scanf("%d%d",&u,&v);

            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        scanf("%d%d",&s,&d);

        for(int i=0;i<n;i++){
           if(i==s) source[i]=0;
           else bfs(i);

           if(i==d) destiny[i]=0;
            else bfs1(i);
        }
        int result=0;
        for(int i=0;i<n;i++){
            //cout<<source[i]<<' '<<destiny[i]<<endl;
            result=max(result,source[i]+destiny[i]);
        }
        printf("Case %d: %d\n",++cas,result);
        for(int i=0;i<mm;i++){
            edges[i].clear();
        }
    }
}
