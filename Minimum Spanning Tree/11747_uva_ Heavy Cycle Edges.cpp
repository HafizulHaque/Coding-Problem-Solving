#include<bits/stdc++.h>
using namespace std;

#define mm 1010
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

    int count=0;vi.clear();

    for(int i=0;i<edges.size();i++){
        int u=find_r(edges[i].u);
        int v=find_r(edges[i].v);

        if(u!=v){
            //cout<<edges[i].u<<' '<<edges[i].v<<' '<<edges[i].w<<endl;
            pr[u]=v;
            count++;
           // if(count==n-1)break;
        }
        if(u==v){
           // cout<<"c "<<edges[i].u<<' '<<edges[i].v<<' '<<edges[i].w<<endl;
            vi.push_back(edges[i].w);
        }
    }
    //cout<<vi.size()<<endl;
    if(vi.size()==0)cout<<"forest"<<endl;
    else{
        for(int i=0;i<vi.size();i++){
            if(i==vi.size()-1)printf("%d\n",vi[i]);
            else printf("%d ",vi[i]);
        }
    }
    vi.clear();
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
        vi.clear();
    }
}
