#include<bits/stdc++.h>
using namespace std;

#define mm 30010
#define pii pair<int,int>

vector<pii>edges[mm];
long long dis1[mm],dis2[mm];

int bfs(int src)
{
    queue<int>q;
    q.push(src);
    dis1[src]=0;

    while(!q.empty()){
        int u=q.front();q.pop();

        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i].first;
            int w=edges[u][i].second;
            if(dis1[v]==-1){
                dis1[v]=dis1[u]+w;
                q.push(v);
            }
        }
    }
    return 0;
}

int bfs2(int src)
{
    queue<int>q;
    q.push(src);
    dis2[src]=0;

    while(!q.empty()){
        int u=q.front();q.pop();

        for(int i=0;i<edges[u].size();i++){
           int v=edges[u][i].first;
            int w=edges[u][i].second;
            if(dis2[v]==-1){
                dis2[v]=dis2[u]+w;
                q.push(v);
            }
        }
    }
    return 0;
}

int main()
{
    int t,cas=0;
    scanf("%d",&t);
    while(t--){
        int n,u,v,w,x,y;
        scanf("%d",&n);

        for(int i=1;i<n;i++){
            scanf("%d%d%d",&u,&v,&w);
            edges[u].push_back(pii(v,w));
            edges[v].push_back(pii(u,w));
        }

        memset(dis1,-1,sizeof(dis1));

        bfs(0);

        int sd,dd;
        long long dis=-1;
        for(int i=0;i<n;i++){
            if(dis1[i]>dis){
                sd=i;
                dis=dis1[i];
            }
        }
        //cout<<sd<<' '<<dis<<endl;

        memset(dis1,-1,sizeof(dis1));

        bfs(sd);

        dis=-1;
        for(int i=0;i<n;i++){
            if(dis1[i]>dis){
                dd=i;
                dis=dis1[i];
            }
        }
       // cout<<dd<<' '<<dis<<endl;

        memset(dis2,-1,sizeof(dis2));

        bfs2(dd);

        printf("Case %d:\n",++cas);
        for(int i=0;i<n;i++){
            //cout<<dis1[i]<<' '<<dis2[i]<<endl;
            printf("%lld\n",max(dis1[i],dis2[i]));
        }

        for(int i=0;i<mm;i++)edges[i].clear();
    }
}
