#include<bits/stdc++.h>
using namespace std;

#define inf 100000000
#define pii pair<int,int>
vector<pii>edges[5010];
int dis[5010][3];

struct st
{
    int u,w;
    st(int a,int b){u=a;w=b;}
    bool operator<(const st &p)const{return w>p.w;}
};
int dijkstra(int n)
{
    for(int i=0;i<=n;i++){
        dis[i][1]=inf;
        dis[i][2]=inf;
    }
    dis[1][1]=0;

    priority_queue<st>q;
    q.push(st(1,0));

    while(!q.empty()){
        st x=q.top();q.pop();
        int u=x.u,c=x.w;

        for(int i=0;i<edges[u].size();i++){
            int uu=edges[u][i].first;
            int cc=edges[u][i].second;
            int ff=dis[uu][1],ss=dis[uu][2];
            if(c+cc<dis[uu][2] and c+cc!=dis[uu][1]){
                dis[uu][2]=c+cc;
                if(dis[uu][2]<dis[uu][1])
                    swap(dis[uu][1],dis[uu][2]);
                q.push(st(uu,c+cc));
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
        printf("Case %d: %d\n",++cs,dis[n][2]);
        for(int i=0;i<5010;i++)edges[i].clear();
    }
}
