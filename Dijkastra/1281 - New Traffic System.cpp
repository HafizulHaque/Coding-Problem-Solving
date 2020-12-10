#include<bits/stdc++.h>
using namespace std;

#define inf 100000000
int dis[10010][20];

struct road
{
    int x,y,z,ex;
    road(int a,int b,int c)
    {
        x=a;z=b;ex=c;
    }
};
struct st
{
    int u,w,e;
    st(int a,int b,int c){u=a;w=b;e=c;}
    bool operator <(const st &p)const {return w>p.w;}
};
vector<road>edges[10010];

int dijkastra(int n,int d)
{
    for(int i=0;i<=n;i++){
        for(int j=0;j<=d;j++)
            dis[i][j]=inf;
    }
    dis[0][0]=0;
    priority_queue<st>q;
    q.push(st(0,0,0));
    while(!q.empty()){
        st x=q.top();q.pop();
        int u=x.u,e=x.e;
        int c=dis[u][e];
        for(int i=0;i<edges[u].size();i++){
            road r=edges[u][i];
            int uu=r.x,cc=r.z,ee=r.ex;

            if(e+ee>d)continue;
            if(c+cc<dis[uu][ee+e]){
                dis[uu][ee+e]=c+cc;
                q.push(st(uu,c+cc,ee+e));
            }
        }
    }
}
int main()
{
    int n,m,k,d,t,cs=0;
    cin>>t;
    while(t--){
        scanf("%d %d %d %d",&n,&m,&k,&d);
        int x,y,z;
        for(int i=0;i<m;i++){
            scanf("%d %d %d",&x,&y,&z);
            edges[x].push_back(road(y,z,0));
        }
        for(int i=0;i<k;i++){
            scanf("%d %d %d",&x,&y,&z);
            edges[x].push_back(road(y,z,1));
        }
        dijkastra(n,d);
        int mx=inf;
        for(int i=0;i<=d;i++){
            mx=min(mx,dis[n-1][i]);
        }
        if(mx!=inf)printf("Case %d: %d\n",++cs,mx);
        else printf("Case %d: Impossible\n",++cs);
        for(int i=0;i<10010;i++)edges[i].clear();
    }
}
