#include<bits/stdc++.h>
using namespace std;

vector<int>edges[20];
int ara[20][20],n,m,w,vis[50];

int dfs(int u,int c)
{
    if(c==n)return 1;
}
int main()
{
    int t,u,v;
    cin>>t;

    for(int c=1;c<=t;c++){
        cin>>n>>m;
        for(int i=0;i<m;i++){
            scanf("%d %d",&u,&v,&w);
            edges[u].push_back(v);
            edges[v].push_back(u);
            ara[u][v]=w;
            ara[v][u]=w;
        }

        for(int i=0;i<edges[0].size();i++){

        }
    }
}
