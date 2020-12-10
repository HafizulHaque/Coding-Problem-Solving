#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define ca 5
#define ru 6
#define c 1
#define r 2
int vis[110][4];
vector<int>edges[110];

int bfs(int src)
{
    queue<pii>q;
    memset(vis,0,sizeof(vis));
    q.push(pii(src,ca));
   // vis[src][c]=1;

    while(!q.empty()){
        pii top=q.front();q.pop();
        int n=top.first;
        int pos=top.second;
       // cout<<n<<' '<<pos<<endl;
        for(int i=0;i<edges[n].size();i++){
            int v=edges[n][i];
            //cout<<v<<' '<<vis[v][c]<<' '<<vis[v][r]<<endl;
            if(vis[v][c]==1 and vis[v][r]==1)continue;
            if(pos==ca and vis[v][r]==1)continue;
            if(pos==ru and vis[v][c]==1)continue;
            if(pos==ca and vis[v][r]==0){
               // cout<<v<<' '<<vis[v][c]<<' '<<vis[v][r]<<" run"<<endl;
                vis[v][r]=1;
                q.push(pii(v,ru));
            }
            if(pos==ru and vis[v][c]==0){
                //cout<<v<<' '<<vis[v][c]<<' '<<vis[v][r]<<" carry"<<endl;
                vis[v][c]=1;
                q.push(pii(v,ca));
            }
        }
    }
}

int main()
{
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        int n,m,u,v,x,y;
        scanf("%d%d",&n,&m);

        for(int i=1;i<=m;i++){
            scanf("%d%d",&u,&v);
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        bfs(1);
        int count=0;
        for(int i=1;i<=n;i++){
            //cout<<vis[i][c]<<endl;
            if(vis[i][c]==1)count++;
        }
        printf("Case %d: %d\n",++cas,count);
        //cout<<count<<endl;
        for(int i=0;i<110;i++)edges[i].clear();
    }
}
