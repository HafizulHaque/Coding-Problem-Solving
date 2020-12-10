#include<bits/stdc++.h>
using namespace std;

#define mm 100010
vector<int>edges[mm];
int vis[mm],n;
long long value=0;
int bfs(int src,int c)
{
        int count=0;

        int u=src;
        vis[src]=1;
        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
            if(vis[v]==1)continue;
            count+=bfs(v,c+1)+1;
        }
        if(src!=1)value+=n-count-c;

    return count;
}
int main()
{
    int t,cas=0;
    scanf("%d",&t);

    while(t--){
        int u,v,x,y;
        scanf("%d",&n);

        memset(vis,0,sizeof(vis));
        for(int i=1;i<n;i++){
            scanf("%d%d",&u,&v);
            edges[u].push_back(v);
            edges[v].push_back(u);
        }
        bfs(1,1);
        printf("Case %d: %d %lld\n",++cas,n-1,value/2);

        value=0;
        for(int i=0;i<mm;i++)edges[i].clear();

    }

}
