// A program that Traverses the nodes of a graph using BFS
#include <bits/stdc++.h>
using namespace std;

class Graph{
    int n;
    list<int> *adj;
public:
    Graph(int n);
    void addEdge(int u, int v);
    void bfs(int starting_node);
};

Graph::Graph(int n){
    this->n = n;
    adj = new list<int>[n+1];
}

void Graph::addEdge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void Graph::bfs(int starting_node){
    int visited[n+1];
    queue<int>q;              // queue
    memset(visited, 0, sizeof(visited));

    visited[starting_node] = 1;
    q.push(starting_node);      // pushing starting node in queue

    while(!q.empty()){
        int item = q.front();
        cout << item << "  " << endl;
        q.pop();
        for(auto itr=adj[item].begin(); itr != adj[item].end(); ++itr){
            if(!visited[*itr]){     // pushing the non visited neighbor nodes in queue
                q.push(*itr);
                visited[*itr] = 1;
            }
        }
    }
    cout << endl;
}


int main(){
    Graph g(8);     // creating instance of graph
    g.addEdge(1,2); // making Edges of the graph
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(2,5);
    g.addEdge(3,6);
    g.addEdge(3,8);
    g.addEdge(6,7);

    g.bfs(7);
    return 0;
}
