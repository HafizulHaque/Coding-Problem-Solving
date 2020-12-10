#include<bits/stdc++.h>
using namespace std;
#define mm 10010

vector<int>edges[mm];
bool vis[mm];
int level[mm];
int n;

int bfs(int src)
{
    queue<int>q;
    memset(vis,0,sizeof(vis));
    memset(level,0,sizeof(level));
    level[src]=0;
    vis[src]=1;
    q.push(src);
    int max=0;
    while(!q.empty()){
        int u=q.front();q.pop();

        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
            if(vis[v]==1)continue;
            level[v]=level[u]+1;
            vis[v]=1;
            max=level[v];
           // cout<<v<<' '<<max<<endl;
            q.push(v);
        }
    }
    //cout<<max<<endl;
    return max;
}
int main()
{
    int u,v,x,y;
    cin>>n;
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
        edges[u].push_back(v);
        edges[v].push_back(u);
    }

    bfs(1);
    int max=-1,s=1;

    for(int i=1;i<=n;i++){
        if(level[i]>max){
            max=level[i];
            s=i;
        }
    }
    //cout<<max<<' '<<s<<endl;
    cout<<bfs(s)<<endl;
}
