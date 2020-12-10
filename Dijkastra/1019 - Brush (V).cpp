#include<bits/stdc++.h>
using namespace std;

#define inf 100000000
#define pii pair<int, int>
vector<pii>edges[110];
int dis[110];

struct pri
{
    int u,w;
    pri(int a,int b){u=a;w=b;}
    bool operator<(const pri &p)const{return w>p.w;}
};

int dijkstra(int n)
{
    priority_queue<pri>q;
    for(int i=1;i<=n;i++)dis[i]=inf;
    q.push(pri(1,0));
    dis[1]=0;
    while(!q.empty()){
        pri x=q.top();q.pop();
        int u=x.u,c=x.w;
        for(int i=0;i<edges[u].size();i++){
            int uu=edges[u][i].first;
            int cc=edges[u][i].second;
            if(c+cc<dis[uu]){
                dis[uu]=c+cc;
                q.push(pri(uu,dis[uu]));
            }
        }
    }
}
int main()
{
   int t,cs=0;
   cin>>t;
   while(t--){
        int n,m,x,y,z;
        scanf("%d %d",&n,&m);
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&x,&y,&z);
            edges[x].push_back(pii(y,z));
            edges[y].push_back(pii(x,z));
        }
        dijkstra(n);
        if(dis[n]==inf)printf("Case %d: Impossible\n",++cs);
        else printf("Case %d: %d\n",++cs,dis[n]);
        for(int i=0;i<110;i++)edges[i].clear();
   }
}
