#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
#define mm 510
int vis[mm];
int pr[mm];
int value[mm];
vector<pii>nodes[mm];

struct vertex   ///node
{
    int u,v,w;
    bool operator <(const vertex& p)const
    {
        return w<p.w;
    }
};

vector<vertex>edges;

int find_r(int r)   ///find representative
{
    if(pr[r]==r)return r;
    else{
        pr[r]=find_r(pr[r]);
        return  pr[r];
    }
}

int mst(int n) ///mst function
{
    sort(edges.begin(),edges.end());

    for(int i=0;i<n;i++)pr[i]=i;

    int count=0,s=0;
    for(int i=0;i<(int)edges.size();i++){
        int u=find_r(edges[i].u);
        int v=find_r(edges[i].v);
        if(u!=v){
            pr[u]=v;
            count++;
            u=edges[i].u;v=edges[i].v;
            int w=edges[i].w;
            //cout<<u<<' '<<v<<' '<<w<<endl;
            nodes[u].push_back(pii(v,w));
            nodes[v].push_back(pii(u,w));
            if(count==n-1)break;
        }
    }
    //cout<<s<<endl;
    return s;
}

int bfs(int src,int max)
{
    int u=src;
    vis[u]=1;

    for(int i=0;i<nodes[u].size();i++){
        int v=nodes[u][i].first;
        int w=nodes[u][i].second;
        if(vis[v]==1)continue;
        //cout<<v<<' '<<w<<endl;
        if(w>max)max=w;
        //cout<<max<<endl;
        value[v]=max;
        bfs(v,max);
    }
    return 0;
}

int main()
{
    int n,m,u,v,w,t,cas=0;
    cin>>t;
    while(t--){
        scanf("%d%d",&n,&m);

        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&u,&v,&w);
            vertex get;
            get.u=u;get.v=v;get.w=w;
            edges.push_back(get);
        }
        memset(vis,0,sizeof(vis));
        memset(pr,0,sizeof(pr));
        memset(value,0,sizeof(value));

        int sr;
        scanf("%d",&sr);

        mst(n);

        int count=0,r=-1;
        for(int i=0;i<n;i++){
            find_r(i);
        }
        //cout<<"bfs"<<endl;
        bfs(sr,0);
        printf("Case %d:\n",++cas);
        //cout<<"final loop"<<endl;
        for(int i=0;i<n;i++){
            if(i==sr)printf("0\n");
            else if(pr[i]!=pr[sr])printf("Impossible\n");
            else printf("%d\n",value[i]);
        }
        edges.clear();
        for(int i=0;i<n;i++)nodes[i].clear();
    }
    return 0;
}



