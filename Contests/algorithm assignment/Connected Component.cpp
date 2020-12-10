#include <bits/stdc++.h>
using namespace std;
vector <int> adj[10];
bool visited[10];
void dfs(int s) {
    visited[s] = true;
    for(int i = 0;i < adj[s].size();++i) {
        if(visited[adj[s][i]] == false)
            dfs(adj[s][i]);
    }
}
void initialize() {
    for(int i = 0;i < 10;++i) visited[i] = false;
}

int main() {
    int nodes, edges, x, y, connectedComponents = 0,  u, v;
    nodes = 7; //Number of nodes
    edges = 6; //Number of edges

    for(int i = 0; i < edges; ++i) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    initialize(); //Initialize all nodes as not visited
    for(int i = 1;i <= nodes;++i) {
        if(visited[i] == false) {
            dfs(i);
            connectedComponents++;
        }
    }
    cout << "Number of connected components: " << connectedComponents << endl;
    return 0;
}


