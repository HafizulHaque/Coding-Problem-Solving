#include<bits/stdc++.h>
using namespace std;

#define mm 1010
#define pii pair<double,double>
vector<pii>node;
int pr[mm];
int range;

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

    int count=0,state=1;
    double s=0,s1=0;

    for(int i=0;i<edges.size();i++){
        int u=find_r(edges[i].u);
        int v=find_r(edges[i].v);
        if(u!=v){
            if(edges[i].w>range){
                state++;s1+=edges[i].w;
            }
            count++;
            pr[u]=v;
            s+=edges[i].w;
            if(count==n-1)break;
        }
    }

    cout<<state<<' '<<round(s-s1)<<' '<<round(s1)<<endl;
}
int main()
{
    int t,cas=0;
    cin>>t;
    while(t--)
    {
        int n,m;
        double u,v,x,y;
        double w;

        scanf("%d%d",&n,&range);

        for(int i=1;i<=n;i++){
            scanf("%lf%lf",&u,&v);
            node.push_back(pii(u,v));
        }

        for(int i=0;i<node.size()-1;i++){
            for(int j=i+1;j<node.size();j++){
                u=node[i].first;v=node[i].second;
                x=node[j].first;y=node[j].second;
                w=sqrt(((u-x)*(u-x))+((v-y)*(v-y)));
                //cout<<i<<' '<<j<<' '<<w<<endl;
                vertex get;
                get.u=i;get.v=j;get.w=w;
                edges.push_back(get);
            }
        }
        printf("Case #%d: ",++cas);
        mst(n);
        edges.clear();
        node.clear();
    }
}

