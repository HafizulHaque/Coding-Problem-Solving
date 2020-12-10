#include<bits/stdc++.h>
using namespace std;

#define mm 1000010
#define lli long long
int pr[mm];
vector<int>vi;

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

    for(int i=0;i<n;i++)pr[i]=i;

    int count=0,max=-1;

    for(int i=0;i<edges.size();i++){
        int u=find_r(edges[i].u);
        int v=find_r(edges[i].v);

        if(u!=v){
            //cout<<edges[i].u<<' '<<edges[i].v<<' '<<edges[i].w<<endl;
            pr[u]=v;
            count++;
            if(edges[i].w>max)max=edges[i].w;
            if(count==n-1)break;
        }
    }
    //cout<<vi.size()<<endl;
  if(count==n-1)cout<<max<<endl;
  else cout<<"IMPOSSIBLE"<<endl;
}

int main()
{
    int n,m;
    while(cin>>n>>m){
        if(n==0 and m==0)break;

        int u,v,w,x,y;

        for(int i=1;i<=m;i++){
            scanf("%d%d%d",&u,&v,&w);

            vertex get;
            get.u=u;get.v=v;get.w=w;
            edges.push_back(get);
        }
        mst(n);
        edges.clear();
    }
}
