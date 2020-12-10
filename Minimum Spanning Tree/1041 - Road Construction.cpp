#include<bits/stdc++.h>
using namespace std;

#define mm 110
vector<string>vi;
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

    for(int i=0;i<n;i++)pr[i]=i;

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
    //cout<<count<<' '<<s<<endl;
    return s;
}
int find_position(string s)
{
    int max=-1;

    for(int i=0;i<vi.size();i++){
        if(vi[i]==s){
            max=i;
            break;
        }
    }
    if(max==-1){
        max=vi.size();
        vi.push_back(s);
    }
    return max;
}
int main()
{
    int t,m,cas=0,w;
    cin>>t;
    while(t--)
    {
        cin>>m;
        string s,s1;
        for(int i=1;i<=m;i++)
        {
            cin>>s>>s1>>w;
            int u=find_position(s);
            int v=find_position(s1);
            vertex get;
            get.u=u;get.v=v;get.w=w;
            //cout<<u<<' '<<v<<' '<<w<<endl;
            edges.push_back(get);
        }
        int n=vi.size();
        int x=mst(n);

        for(int i=0;i<n;i++)find_r(i);

        int p=-1,count=0;
        for(int i=0;i<n;i++){
            if(pr[i]!=p){
                p=pr[i];
                count++;
            }
        }
        //cout<<count<<' '<<x<<endl;

        if(count>1)printf("Case %d: Impossible\n",++cas);
        else printf("Case %d: %d\n",++cas,x);
        vi.clear();
        edges.clear();
    }
}

