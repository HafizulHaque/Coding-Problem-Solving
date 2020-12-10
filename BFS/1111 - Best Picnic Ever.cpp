#include<bits/stdc++.h>
using namespace std;
#define mm 1010
vector<int>edges[mm],v;
int vis[mm][mm];
int n,m,k;

int bfs(int src)
{
    vis[src][src]=1;
    queue<int>q;
    int visited[mm];
    memset(visited,0,sizeof(visited));
    visited[src]=1;
    q.push(src);

    while(!q.empty()){
        int u=q.front();q.pop();

        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
            //cout<<v<<endl;
            while(!visited[v]){
                visited[v]=1;
                //cout<<src<<' '<<v<<endl;
                vis[src][v]=1;
                q.push(v);
            }
        }
    }
    return 0;
}
int main()
{
    int t,cas=0;
    cin>>t;
    while(t--){
        int u,x,y;
        memset(vis,0,sizeof(vis));
        scanf("%d%d%d",&k,&n,&m);
        for(int i=0;i<k;i++){
            scanf("%d",&u);
            v.push_back(u);
        }

        for(int i=0;i<m;i++){
            scanf("%d%d",&x,&y);
            edges[x].push_back(y);
        }

        for(int i=0;i<v.size();i++){
            int a=v[i];
            //cout<<a<<endl;
            bfs(a);
        }

        int count=0;
        for(int i=1;i<=1010;i++){
                int flag=1;
            for(int j=0;j<v.size();j++){
                int f=v[j];
                //cout<<f<<' '<<i<<' '<<vis[f][i]<<endl;
                if(vis[f][i]==0){
                    flag=0;
                    break;
                }
            }
            if(flag==1)count++;
        }

        printf("Case %d: %d\n",++cas,count);
        v.clear();
        for(int i=0;i<=mm;i++){
            edges[i].clear();
        }
    }
}
