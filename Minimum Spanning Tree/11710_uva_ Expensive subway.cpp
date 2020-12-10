#include<bits/stdc++.h>
using namespace std;

#define mm 420
int pr[mm];
map<string,int>mp;

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

    for(int i=0;i<edges.size();i++){
        int u=find_r(edges[i].u);
        int v=find_r(edges[i].v);

        if(u!=v){
            pr[u]=v;
            count++;
            s+=edges[i].w;
            if(count==n-1)break;
        }
    }
    if(count==n-1)cout<<s<<endl;
    else cout<<"Impossible"<<endl;
}

int main()
{
    int n,m;
    while(cin>>n>>m){
        if(n==0 and m==0) break;
        string s,s1;
        for(int i=0;i<n;i++){
            cin>>s;
            mp[s]=i;
        }
        int u,v,w;
        for(int i=0;i<m;i++){
            cin>>s>>s1>>w;
            u=mp.at(s);v=mp.at(s1);
            vertex get;
            get.u=u;get.v=v;get.w=w;
            edges.push_back(get);
        }
        cin>>s;
        mst(n);
        mp.clear();
        edges.clear();
    }
}
