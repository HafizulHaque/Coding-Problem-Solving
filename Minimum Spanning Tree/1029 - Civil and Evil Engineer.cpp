#include<bits/stdc++.h>
using namespace std;

#define mm 110
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

    for(int i=0;i<=n;i++)pr[i]=i;

    int count=0,s=0;

    for(int i=0;i<(int)edges.size();i++){
        int u=find_r(edges[i].u);
        int v=find_r(edges[i].v);

        if(u!=v){
            pr[u]=v;
            count++;
            s+=edges[i].w;
            if(count==n)break;
        }
    }
    //cout<<s<<endl;

    int s1=0;
    count=0;

    for(int i=0;i<=n;i++)pr[i]=i;

    for(int i=(int)edges.size()-1;i>=0;i--){
        int u=find_r(edges[i].u);
        int v=find_r(edges[i].v);

        if(u!=v){
            pr[u]=v;
            count++;
            s1+=edges[i].w;
            if(count==n)break;
        }
    }
   // cout<<s1<<endl;
    return s+s1;
}

int main()
{
    int t,cas=0;
    scanf("%d",&t);

    while(t--){
        int u,v,w,n;
        scanf("%d",&n);
        while(scanf("%d%d%d",&u,&v,&w)){
            if(u==0 and v==0 and w==0)
                break;
            vertex get;
            get.u=u;get.v=v;get.w=w;
            edges.push_back(get);
        }
        int x=mst(n);
        printf("Case %d: ",++cas);
        if(x%2==0)cout<<(x/2)<<endl;
        else cout<<x<<"/2"<<endl;
        edges.clear();
    }
}
