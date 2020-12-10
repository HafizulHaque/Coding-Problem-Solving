#include<bits/stdc++.h>
using namespace std;

#define lli long long
#define max 100009
#define inf 10000000000000000
#define pii pair<lli,lli>
#define pb(x) push_back(x)
#define nill 0

struct comp
{
    bool operator()(const pii &a,const pii &b)
    {
        return a.second>b.second;
    }
};

priority_queue<pii,vector<pii>,comp>q;
lli d[max];
lli f[max];
lli parent[max];
vector<pii> edges[max];

int dijkastra(lli src,lli n)
{
    for(lli i=1;i<=n;i++){
        d[i]=inf;
        parent[i]=nill;
    }
    d[src]=0;
    q.push(pii(src,0));

    while(!q.empty())
    {
        lli u=q.top().first;
        q.pop();
        if(f[u])continue;
        lli sz=edges[u].size();

        for(lli i=0;i<sz;i++){
            lli v=edges[u][i].first;
            lli w=edges[u][i].second;

            if(d[u]+w<d[v]){
                d[v]=d[u]+w;
                parent[v]=u;
                q.push(pii(v,d[v]));
            }
        }
        f[u]=1;
    }
}

int main()
{
    int n,e,u,v,w;

    cin>>n>>e;

    for(lli i=0;i<e;i++){
       cin>>u>>v>>w;
        edges[u].pb(pii(v,w));
        edges[v].pb(pii(u,w));
    }
    memset(f,0,sizeof(f));
    dijkastra(1,n);

    vector<lli>vi;

    lli j=n;

    while(1){
        //cout<<j<<endl;
        vi.push_back(j);
        if(j==1 or j==0)break;
        j=parent[j];
        //if(j==0)break;
    }
    if(j==1){
        for(lli i=vi.size()-1;i>=0;i--){
            if(i==0)cout<<vi[i]<<endl;
            else cout<<vi[i]<<' ';
        }
    }
    else{
        cout<<-1<<endl;
    }

}
