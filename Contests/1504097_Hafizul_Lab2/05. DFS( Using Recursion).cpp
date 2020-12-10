#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;  // no of nodes
    list<int> *adj;     // adjacancy list
    void DFSUtil(int v, bool visited[]);
public:
    Graph(int V);   // Constructor
    void addEdge(int v, int w);
    void DFS(int v);
};

Graph::Graph(int V){    // constructor
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){  // adding edges to graph
    adj[v].push_back(w);
}

void Graph::DFSUtil(int v, bool visited[]){
    visited[v] = true;
    cout << v << " ";
    list<int>::iterator i;

    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            DFSUtil(*i, visited);   // recursive call of DFSUtil function
}

void Graph::DFS(int v){
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;
    DFSUtil(v, visited);
}


int main(){

    Graph g(4); // initialize graph g
    g.addEdge(0, 1);    // adding Edges
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "Following is Depth First Traversal" << " (starting from vertex 2) \n";
    g.DFS(2);
    return 0;

}



