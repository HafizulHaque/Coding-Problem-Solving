
// A program that determines shortest path between two nodes using Dijsktra's shortest path algorithm

#include <bits/stdc++.h>
using namespace std;
#define N 7     // number of nodes
int adj[N+1][N+1];

int main(){
    FILE *inp = freopen("dijsktra_input.txt", "r", stdin);  // taking input from external txt file
    int u, v, cost;
    for(int i = 1; i < 10; ++i){    // adding edges
        cin>>u>>v>>cost;
        adj[u][v] = cost;
        adj[v][u] = cost;
    }

    int distance[N+1];
    queue<int>q;
    int starting_node = 1, ending_node = 7;
    for(int i = 0; i <= N; ++i) distance[i] = INT_MAX;  // initializing distance of all nodes to infinity

    distance[starting_node] = 0;
    q.push(starting_node);

    while(!q.empty()){
        int item = q.front();
        q.pop();
        for(int i = 1; i <= N; ++i){
            if(adj[item][i] && adj[item][i]+distance[item]<distance[i]){    // dijsktra update method
                q.push(i);
                distance[i] = distance[item]+adj[item][i];
            }
        }
    }
    cout << "shortest distance :" << distance[ending_node] << endl; // printing distance from source
    fclose(inp);    // closing input file
    return 0;
}
