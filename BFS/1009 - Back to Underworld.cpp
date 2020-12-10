#include<bits/stdc++.h>
using namespace std;

//#define clean(a,b) memset(a,0,sizeof(0))
#define mm 20010
vector<int> edges[mm];
int visited[mm];

int bfs(int src)
{
    queue<int>q;
    q.push(src);
    visited[src]=1;
    int count1=1,count2=0;

    while(!q.empty()){
        int u=q.front();q.pop();
        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
            if(visited[v]==0){
                    //cout<<v<<' '<<visited[u]<<endl;
                if(visited[u]==1){
                    visited[v]=2;
                    count2++;
                }
                else {
                    visited[v]=1;
                    count1++;
                }
                q.push(v);
            }
        }
    }
    //cout<<count1<<' '<<count2<<endl;
    int m=max(count1,count2);
    return m;
}

int main()
{
    int t,cas=0;
    cin>>t;

    while(t--){
        int n,u,v;
        scanf("%d",&n);

        for(int i=0;i<n;i++){
            scanf("%d%d",&u,&v);
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        //clean(visited,0);
        memset(visited,0,sizeof(visited));

        long long value=0;
        for(int i=1;i<mm;i++){
            if(edges[i].size()==0)continue;
            if(visited[i]==0){
                //cout<<i<<' '<<visited[i]<<endl;
                int z=bfs(i);
                value+=z;
            }
        }
        printf("Case %d: %lld\n",++cas,value);

        for(int i=0;i<mm;i++){
            edges[i].clear();
        }
        //cout<<value<<endl;
    }
}
