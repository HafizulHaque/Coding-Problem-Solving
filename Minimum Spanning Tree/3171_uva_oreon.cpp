#include<bits/stdc++.h>
using namespace std;

#define mm 50
int pr[mm];
char o='A';
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

    int count=0;

    for(int i=0;i<edges.size();i++){
        int u=find_r(edges[i].u);
        int v=find_r(edges[i].v);

        if(u!=v){
            pr[u]=v;
            count++;
            u=edges[i].u;v=edges[i].v;
            int w=edges[i].w;
            cout<<char(o+u)<<'-'<<char(o+v)<<' '<<w<<endl;
            if(count==n-1)break;
        }
    }
    return 0;
}

int main()
{
    int t,cas=0,u,v,w;
    char c;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cin>>w;
                if(j<n-1)cin>>c;
                if(w==0)continue;
                if(i<j){
                    vertex get;
                    get.u=i;get.v=j;get.w=w;
                    edges.push_back(get);
                }
            }
        }

        printf("Case %d:\n",++cas);
        mst(n);
        edges.clear();
    }
}
