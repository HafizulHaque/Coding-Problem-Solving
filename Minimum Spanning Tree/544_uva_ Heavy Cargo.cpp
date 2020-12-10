#include<bits/stdc++.h>
using namespace std;

#define mm 210
#define pii pair<int,int>
int vis[mm];
int value[mm];
vector<pii>nodes[mm];
vector<string>vs;
int pr[mm];

struct vertex   ///node
{
    int u,v,w;
    bool operator <(const vertex& p)const
    {
        return w>p.w; ///maximum spanning tree
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

int mst(int n)
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
            s+=edges[i].w;
            if(count==n-1)break;
        }
    }
   // cout<<s<<endl;
    return s;
}
int bfs(int src,int ds,int mi)
{
    int u=src;
    vis[u]=1;
    if(src==ds)return 0;

    for(int i=0;i<nodes[u].size();i++){
        int v=nodes[u][i].first;
        int w=nodes[u][i].second;
       // cout<<v<<' '<<w<<endl;
        if(vis[v]==1)continue;

        if(w<mi)mi=w;
        //cout<<v<<' '<<mi<<endl;
        value[v]=mi;
        bfs(v,ds,mi);
    }
    return 0;
}

int find_position(string s)
{
    int max=-1;

    for(int i=0;i<vs.size();i++){
        if(s==vs[i]){
            max=i;
            break;
        }
    }

    if(max==-1){
        max=vs.size();
        vs.push_back(s);
    }
    return max;
}

int main()
{
    int n,m,u,v,w,cas=0;
    string s,s1;

    while(cin>>n>>m){
            if(n==0 or m==0) break;
            for(int i=1;i<=m;i++){
                cin>>s>>s1>>w;
                u=find_position(s); v=find_position(s1);
                vertex get;
               // cout<<u<<' '<<v<<endl;
                get.u=u;get.v=v;get.w=w;
                edges.push_back(get);
            }

            memset(vis,0,sizeof(vis));
            memset(pr,0,sizeof(pr));
            memset(value,0,sizeof(value));

            int sr,ds;
            cin>>s>>s1;
            sr=find_position(s);
            ds=find_position(s1);
           // cout<<sr<<' '<<ds<<endl;
            mst(n);
            bfs(sr,ds,10000000);
            printf("Scenario #%d\n",++cas);
            cout<<value[ds]<<" tons"<<endl<<endl;
            vs.clear();
            edges.clear();

            for(int i=0;i<mm;i++)nodes[i].clear();
    }
}
