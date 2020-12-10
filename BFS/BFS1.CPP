#include<iostream>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
#define max 100
vector<int>edges[max];
void bfs(int e,int src)
{
    queue<int>q;
    q.push(src);
    int visited[max]={0},level[max];
    int parent[max];
    visited[src]=1;
    level[src]=0;

    while(!q.empty()){
        int u=q.front();
        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
            if(!visited[v]){
                level[v]=level[u]+1;
                parent[v]=u;
                visited[v]=1;
                q.push(v);
            }
        }
        q.pop();
    }
    for(int i=1;i<=e;i++){
        printf("%d to %d distance %d\n",src,i,level[i]);
    }
}
int main()
{
  int N,E,x,y;
  freopen("t.txt","r",stdin);
  cin>>N>>E;

  for(int i=1;i<=E;i++){
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
  }
  bfs(N,1);
  return 0;
}
