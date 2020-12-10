#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cstdio>
using namespace std;
vector<int>edges[100010];

int bfs(int src,int b)
{
    queue<int>q;
    q.push(src);
    int visited[100010]={0},level[100010]={0};
    visited[src]=1;
    level[src]=0;
    while(!q.empty()){
        int u=q.front();
        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
            if(visited[v]==0){
                level[v]=level[u]+1;
                visited[v]=1;
                q.push(v);
            }
        }
        q.pop();
    }
    return level[b]-1;
}
int main()
{
    int flag=1;
    int t;
    cin>>t;
    for(int o=0;o<t;o++){
        if(flag++>1)
            cout<<endl;
        int n,p,q,r,s,t;
        scanf("%d",&n);
        for(int i=0;i<n;i++){
            scanf("%d%d",&p,&q);
            for(int j=0;j<q;j++){
                scanf("%d",&r);
                edges[p].push_back(r);
            }
        }
        scanf("%d%d",&r,&s);
        t=bfs(r,s);
        cout<<r<<' '<<s<<' '<<t<<endl;
        for(int i=0;i<100010;i++)edges[i].clear();
    }
}
