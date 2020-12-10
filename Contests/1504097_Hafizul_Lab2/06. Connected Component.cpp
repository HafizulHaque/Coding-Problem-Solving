#include <bits/stdc++.h>
using namespace std;
vector <int> adj[10];
bool visited[10];

void dfs(int s) {           // marking connected nodes using dfs
    visited[s] = true;
    for(int i = 0; i < adj[s].size(); ++i) {
        if(visited[adj[s][i]] == false)
            dfs(adj[s][i]);
    }
}
void initialize() {     // initialize all nodes as unvisited initially
    for(int i = 0; i < 10; ++i) visited[i] = false;
}

int main() {
    int nodes, edges, x, y, connectedComponents = 0;
    nodes = 7; //Number of nodes
    edges = 6; //Number of edges
    int edgelist[6][2] = {          // Edge list
                            {0,1},{0,2},{1,3},{1,4},{2,5},{2,6}
                        };

    for(int i = 0; i < edges; ++i) {    // adding edges
        adj[edgelist[i][0]].push_back(edgelist[i][1]);
        adj[edgelist[i][1]].push_back(edgelist[i][0]);
    }
    initialize(); //Initialize all nodes as not visited

    for(int i = 1;i <= nodes;++i) { // counting all connected components
        if(visited[i] == false) {
            dfs(i);
            connectedComponents++;
        }
    }
    cout << "Number of connected components: " << connectedComponents << endl;
    return 0;
}


