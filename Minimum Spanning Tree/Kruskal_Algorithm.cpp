#include<bits/stdc++.h>
using namespace std;

struct vertex   ///node
{
    int u,v,w;
    bool operator <(const vertex& p)const
    {
        return w<p.w;
    }
};
#define mm 1000
int pr[mm];
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

    for(int i=1;i<=n;i++)pr[i]=i;

    int count=0,s=0;
    //cout<<edges.size()<<' '<<(int)edges.size()<<endl;
    for(int i=0;i<(int)edges.size();i++){
        int u=find_r(edges[i].u);
        int v=find_r(edges[i].v);
        if(u!=v){
            pr[u]=v;
            count++;
            cout<<edges[i].u<<' '<<edges[i].v<<' '<<edges[i].w<<endl;
            s+=edges[i].w;
            if(count==n-1)break;
        }
    }
    return s;
}

int main()
{
    int n,m,u,v,w;
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>u>>v>>w;
        vertex get;
        get.u=u;get.v=v;get.w=w;
        edges.push_back(get);
    }

    cout<<mst(n)<<endl;
    return 0;
}


