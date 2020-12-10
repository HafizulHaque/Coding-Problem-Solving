#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<cstdio>
#include<cstring>
using namespace std;
vector<int>edges[110];
int cost[110][110];
int t,e,n;
int bfs(int src)
{
    int d[n+1];
    for(int i=0;i<n;i++)
        d[i]=100000000;
    queue<int>q;
    q.push(src);
    d[src]=0;
    int flag=0;
    while(!q.empty()){
        int u=q.front();
        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
            if(d[u]+cost[u][v]<d[v]){
                d[v]=d[u]+cost[u][v];
                q.push(v);
            }
        }
        q.pop();
    }
    if(d[e]<=t){
        return 1;
    }
    else{
        return -1;
    }
}

int main()
{
    int x;
    cin>>x;
    for(int o=1;o<=x;o++){
        if(o>1)
            cout<<endl;
        int m,x,y,z;
        cin>>n>>e>>t>>m;
       // memset(cost,0,sizeof(cost));
        for(int i=1;i<=m;i++){
            cin>>x>>y>>z;
            edges[x].push_back(y);
            cost[x][y]=z;
        }

        int count=0;

        for(int i=1;i<=n;i++){
           int z=bfs(i);
           if(z==1)
            count++;
        }

        cout<<count<<endl;

        for(int i=0;i<110;i++)
            edges[i].clear();
    }
    return 0;
}
