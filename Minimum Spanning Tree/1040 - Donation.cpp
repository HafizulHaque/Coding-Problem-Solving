#include<bits/stdc++.h>
using namespace std;

#define mm 300
int pr[mm];

struct vertex
{
    int u,v,w;

    bool operator <(const vertex &p)const
    {
        return w<p.w;
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

    for(int i=1;i<=n;i++)pr[i]=i;

    int count=0,s=0;
    for(int i=0;i<(int)edges.size();i++){
        int u=find_r(edges[i].u);
        int v=find_r(edges[i].v);
        if(u!=v){
            pr[u]=v;
            count++;
            s+=edges[i].w;
            if(count==n-1)break;
        }
    }
    if(count==n-1)
        return s;
    else return -1;
}

int main()
{
    int n,t,u,v,w,cas=0;
    scanf("%d",&t);

    while(t--){
        scanf("%d",&n);
        int s=0;
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                scanf("%d",&w);
                s+=w;
                if(i==j)continue;
                if(w==0)continue;
                vertex get;
                get.u=i;get.v=j;get.w=w;
                edges.push_back(get);
            }
        }

        int x=mst(n);
        if(x==-1)printf("Case %d: -1\n",++cas);
        else printf("Case %d: %d\n",++cas,s-x);
        edges.clear();
    }
}
