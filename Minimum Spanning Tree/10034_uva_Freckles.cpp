#include<bits/stdc++.h>
#include<cstdio>
using namespace std;

#define pii pair<double,double>
#define mm 110
int pr[mm];
vector<pii>node;

struct vertex
{
    int u,v;
    double w;
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
    int count=0;
    double s=0;
    for(int i=0;i<edges.size();i++){
        int u=find_r(edges[i].u);
        int v=find_r(edges[i].v);

        if(u!=v){
            count++;
            pr[u]=v;
            s+=edges[i].w;
            if(count==n-1)break;
        }
    }
    cout<<fixed<<setprecision(2)<<s<<endl;
}
int main()
{
    int t,cas=0;
    cin>>t;
    while(t--){
        if(cas++>0)cout<<endl;

        int n;
        double u,v,x,y,w;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>x>>y;
            node.push_back(pii(x,y));
        }

        for(int i=0;i<node.size()-1;i++){
            for(int j=i+1;j<node.size();j++){
                u=node[i].first;v=node[i].second;
                x=node[j].first;y=node[j].second;
                w=sqrt(((u-x)*(u-x))+((v-y)*(v-y)));
                //cout<<w<<endl;
                vertex get;
                get.u=i;get.v=j;get.w=w;
                edges.push_back(get);
            }
        }
        mst(n);
        edges.clear();
        node.clear();

    }
}
