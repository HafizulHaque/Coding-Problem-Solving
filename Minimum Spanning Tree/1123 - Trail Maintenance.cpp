#include<bits/stdc++.h>
using namespace std;

#define mm 210
#define pii pair<int,int>
int pr[mm];

struct vertex
{
    int u,v,w;
    bool operator <(const vertex &p)const
    {
        return w<p.w;
    }
};
vector<vertex>edges,nodes;

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

    for(int i=1;i<=n;i++)pr[i]=i;
    int count=0,s=0;

    for(int i=0;i<(int)edges.size();i++){
        int u=find_r(edges[i].u);
        int v=find_r(edges[i].v);

        if(u!=v){
            vertex get;
            get.u=edges[i].u;get.v=edges[i].v;get.w=edges[i].w;
            nodes.push_back(get);
            pr[u]=v;
            count++;
            s+=edges[i].w;
            if(count==n-1)break;
        }
    }
    edges.clear();
    edges=nodes;
    nodes.clear();
    if(count==n-1)return s;
    else return -1;
}

int main()
{
        int t,cas=0;
        scanf("%d",&t);
        while(t--){
            int n,m,u,v,w;
            scanf("%d%d",&n,&m);
            int x=0;
            printf("Case %d:\n",++cas);
            int flag=0;
            for(int i=1;i<=m;i++){
                scanf("%d%d%d",&u,&v,&w);
                vertex get;
                get.u=u;get.v=v;get.w=w;
                edges.push_back(get);
                printf("%d\n",mst(n));
            }
            edges.clear();

        }
}
