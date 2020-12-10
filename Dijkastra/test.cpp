#include<bits/stdc++.h>
#include<queue>
#include<vector>
using namespace std;

#define MAX 100001
#define inf (1<<20)
#define pii pair<int,int>
#define pb(x) push_back(x)
#define nill 0
struct comp
{
    bool operator()(const pii &a, const pii &b)
    {
        return a.second>b.second;
    }
};

priority_queue<pii,vector<pii>,comp>q;
vector<pii>edges[MAX];
int d[MAX];
int parent[MAX];
bool F[MAX];


int dijkstra(int src,int n)
{
    for(int i=1;i<=n;i++){
        d[i]=inf;
        parent[i]=nill;
    }
    d[src]=0;
    q.push(pii(src,0));

    while(!q.empty())
    {
        int u=q.top().first;
        q.pop();
        if(F[u]==1)continue;

        int sz=edges[u].size();

        for(int i=0;i<sz;i++){
            int v=edges[u][i].first;
            int w=edges[u][i].second;
            cout<<u<<' '<<v<<' '<<w<<endl;
            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                parent[v]=u;
                q.push(pii(v,d[v]));
            }
        }
        F[u]=1;
    }

}
int main()
{
    int n,e,u,v,w,start;
    cin>>n>>e;

    for(int i=0;i<e;i++){
        scanf("%d%d%d",&u,&v,&w);
        edges[u].pb(pii(v,w));
    }
    scanf("%d",&start);

    memset(F,0,sizeof(F));
    dijkstra(start,n);

    for(int i=1;i<=n;i++){
        cout<<i<<" weight from source "<<d[i]<<endl;
        int j=parent[i];
        while(j!=0){
            cout<<j<<"--->";
            j=parent[j];
        }
        cout<<endl;
    }

    return 0;
}


