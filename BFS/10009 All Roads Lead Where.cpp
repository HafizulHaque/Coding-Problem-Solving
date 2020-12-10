#include<iostream>
#include<map>
#include<queue>
#include<vector>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
vector<int>edges[10000];
vector<char>nodes_n;
map <string, int> nodes;

void bfs(int src,int b)
{
    queue<int>q;
    q.push(src);
    int visited[10000]={0},level[10000]={0};
    int parent[10000]={0};
    visited[src]=1;
    parent[src]=src;
    level[src]=0;

    while(!q.empty()){
        int u=q.front();
        for(int i=0;i<edges[u].size();i++){
            int v=edges[u][i];
            if(visited[v]==0){
                level[v]=level[u]+1;
                visited[v]=1;
                parent[v]=u;
                q.push(v);
            }
        }
        q.pop();
    }

    vector<char>my;
    my.push_back(nodes_n[b-1]);

    while(b!=src){
        b=parent[b];
        my.push_back(nodes_n[b-1]);
    }

    reverse(my.begin(), my.end());

    for(int i=0;i<my.size();i++)
        cout<<my[i];
    cout<<endl;
}

int main()
{
    int t;
    int flag=0;
    cin>>t;
    for(int o=1;o<=t;o++){
        if(flag++>0)
            cout<<endl;
        nodes.clear();
        nodes_n.clear();
        int m,n;
        cin>>m>>n;
        string a,b;
        int x=0;
        for(int i=1;i<=m;i++){
            cin>>a>>b;
            if(nodes[a]==0){
                nodes[a]=++x; nodes_n.push_back(a[0]);
            }
            if(nodes[b]==0){
                nodes[b]=++x; nodes_n.push_back(b[0]);
            }
            edges[nodes[a]].push_back(nodes[b]);
            edges[nodes[b]].push_back(nodes[a]);
        }
        int src,dst;

        for(int i=1;i<=n;i++){
            cin>>a>>b;
            src=nodes[a],dst=nodes[b];
            bfs(src,dst);
        }

        for(int i=0;i<10000;i++)edges[i].clear();
    }
}
