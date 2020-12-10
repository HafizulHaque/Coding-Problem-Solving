#include<bits/stdc++.h>
using namespace std;

#define mm 2010
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
            count++;
            pr[u]=v;
            s+=edges[i].w;
            if(count==n-1)break;
        }
    }
    return s;
}

int main()
{
    int t,cas=0;
    cin>>t;
    while(t--){
        map<string,int>mapping;
        if(cas>0)cout<<endl;
        int n,m,w,x=1;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
                int u,v;
            string s,s1;
            cin>>s>>s1>>w;

            if(mapping.find(s)==mapping.end()){
                 mapping[s]=x;
                 u=x;
                 x++;
            }
            else u=mapping.at(s);
            if(mapping.find(s1)==mapping.end()){
                 mapping[s1]=x;
                 v=x;
                 x++;
            }
            else v=mapping.at(s1);
           //cout<<u<<' '<<v<<' '<<endl;
            vertex get;
            get.u=u;get.v=v;get.w=w;
            edges.push_back(get);
        }

        cout<<mst(n)<<endl;
        edges.clear();
        mapping.clear();
        cas++;
    }
}
