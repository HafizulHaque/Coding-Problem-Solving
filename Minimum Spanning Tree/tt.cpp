#include<bits/stdc++.h>
using namespace std;

#define mm  200010
#define lli int
lli pr[mm];

struct vertex
{
    lli u,v,w;
    bool operator <(const vertex &p)const
    {
        return w<p.w;
    }
};
vector<vertex>edges;

lli find_r(lli r)
{
    if(pr[r]==r)return r;
    else{
        pr[r]=find_r(pr[r]);
        return pr[r];
    }
}

lli mst(lli n)
{
    sort(edges.begin(),edges.end());

    for(lli i=0;i<n;i++)pr[i]=i;
    lli count=0,s=0;

    for(lli i=0;i<edges.size();i++){
        lli u=find_r(edges[i].u);
        lli v=find_r(edges[i].v);
        if(u!=v){
            pr[u]=v;
            count++;
            s+=edges[i].w;
            if(count==n-1)break;
        }
    }
   /// cout<<s<<endl;
    return s;
}
int main()
{
    lli m,n,u,v,x,y,w,sum;

    while(scanf("%d%d",&n,&m)){
        if(n==0 and m==0)break;
        sum=0;
        for(int i=1;i<=m;i++){
           scanf("%d%d%d",&u,&v,&w);
            sum+=w;
            vertex get;
            get.u=u;get.v=v;get.w=w;
            edges.push_back(get);
        }
        x=mst(n);
        printf("%d\n",sum-x);
        edges.clear();
    }
}

