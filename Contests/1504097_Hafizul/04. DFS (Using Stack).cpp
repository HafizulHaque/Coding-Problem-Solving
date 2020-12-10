// traversing all nodes of the graph by DFS ( Depth First Search )

#include <bits/stdc++.h>
using namespace std;

class Graph{    // class for representing the graph
    int V;
    list<int> *adj; // adjacency list
public:
    Graph(int v);
    void addEdge(int u, int v);
    void DFS(int s);
};

Graph::Graph(int v){    // initializing the Graph class
    this->V = v;
    adj = new list<int>[V+1];
}

void Graph::addEdge(int u, int v){  // adding Edges to graph
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void Graph::DFS(int s){
    int visited[V+1];
    for(int i = 0; i <= V; ++i) visited[i] = 0; // init all vertex as unvisited
    stack<int>st;       // stack for the dfs
    st.push(s);         // pushing the starting node in the stack

    while(!st.empty()){
        int top = st.top();
        st.pop();
        if(!visited[top]){              // dfs
            cout << top << "  " << endl;
            visited[top] = 1;
            for(auto itr = adj[top].begin(); itr != adj[top].end(); ++itr){
                if(!visited[*itr]) st.push(*itr);
            }
        }
    }
}

int main(){
    Graph g(7);     // initialize the graph
    g.addEdge(1,2); // adding edges
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(2,5);
    g.addEdge(3,6);
    g.addEdge(3,7);

    cout << "traversing starting from node" << 1 << " as source node using dfs is:" << endl;
    g.DFS(1);
    return 0;
}



