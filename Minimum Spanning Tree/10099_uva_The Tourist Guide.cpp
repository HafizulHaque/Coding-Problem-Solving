#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,lli>
#define lli long long
#define mm 110
int pr[mm];
int vis[mm];
vector<pii>nodes[mm];
int sr,des,t;
lli mi;
struct vertex
{
    int u,v;
    lli w;

    bool operator <(const vertex &p)const
    {
        return w>p.w;
    }
};
vector<vertex>edges;

int find_r(int r)
{
    if(pr[r]==r)return r;
    else{
        pr[r]=find_r(pr[r]);
        return pr[r];
    }
}
int mst(int n)
{
    sort(edges.begin(),edges.end());

    for(int i=0;i<=n;i++)pr[i]=i;

    int count=0;

    for(int i=0;i<edges.size();i++){
        int u=find_r(edges[i].u);
        int v=find_r(edges[i].v);

        if(u!=v){
            u=edges[i].u;v=edges[i].v;
            lli w=edges[i].w;
            //cout<<u<<' '<<v<<' '<<w<<endl;

            nodes[u].push_back(pii(v,w));
            nodes[v].push_back(pii(u,w));
            count++;
            if(count==n-1)break;
        }
    }
}
int bfs(int src)
{
   vis[src]=1;

   for(int i=0;i<nodes[src].size();i++){
        int v=nodes[src][i].first;
        lli w=nodes[src][i].second;
        //cout<<v<<' '<<w<<endl;
        if(vis[v]==1)continue;
        else{
            if(w<mi)mi=w;
            if(v==des)return 0;
            bfs(v);
        }
   }
   return 0;
}

int main()
{
  int n,m,u,v,x,y,cas=0;
  lli w,t;

  while(cin>>n>>m){
        if(n==0 and m==0)break;
    for(int i=0;i<m;i++){
        cin>>u>>v>>w;
        vertex get;
        get.u=u;get.v=v;get.w=w;
        edges.push_back(get);
    }
    cin>>sr>>des>>t;

    memset(vis,0,sizeof(vis));

    mst(n);
    mi=1000000000000000000;
    bfs(sr);
    mi-=1;
    //cout<<mi<<endl;
    printf("Scenario #%d\n",++cas);
    if(t%mi==0)printf("Minimum Number of Trips = %lld\n",t/mi);
    else printf("Minimum Number of Trips = %lld\n",(t/mi)+1);
    cout<<endl;
    edges.clear();
    for(int i=0;i<mm;i++)nodes[i].clear();
  }
}
