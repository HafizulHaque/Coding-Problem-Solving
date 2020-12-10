#include<iostream>
#include<vector>
#include<map>
#include<queue>
#include<cstdio>
#include<cstring>
using namespace std;
vector<int>edges[21000];
int cost[20001][20001];

int bfs(int src,int b,int c)
{
    int d[c+1];
    for(int i=0;i<c;i++)
        d[i]=100000000;
    queue<int>q;
    q.push(src);
    d[src]=0;
    int flag=0;
    while(!q.empty()){
        int u=q.front();
        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
            if(v==b)
                flag=1;
            if(d[u]+cost[u][v]<d[v]){
                d[v]=d[u]+cost[u][v];
                q.push(v);
            }
        }
        q.pop();
    }
    if(flag==0){
        return -1;
    }
    else{
        return d[b];
    }
}

int main()
{
    int t;
    cin>>t;
    for(int o=1;o<=t;o++){
        int m,n,p,q,r,s,w;
        cin>>m>>n>>p>>q;
        for(int i=0;i<n;i++){
            cin>>r>>s>>w;
            edges[r].push_back(s);
            edges[s].push_back(r);
            cost[r][s]=w;
            cost[s][r]=w;
        }

        if(n<1)
            cout<<"Case #"<<o<<": unreachable"<<endl;
        else{
           int z=bfs(p,q,m);
           if(z==-1)
            cout<<"Case #"<<o<<": unreachable"<<endl;
           else
             cout<<"Case #"<<o<<": "<<z<<endl;
        }
        for(int i=0;i<21000;i++)
            edges[i].clear();
    }
}
