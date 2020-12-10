#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int v);
    void addEdge(int u, int v);
    void DFS(int s);
};

Graph::Graph(int v){
    this->V = v;
    adj = new list<int>[V+1];
}

void Graph::addEdge(int u, int v){
    adj[v].push_back(u);
    adj[u].push_back(v);
}

void Graph::DFS(int s){
    int visited[V+1];
    for(int i = 0; i <= V; ++i) visited[i] = 0;
    stack<int>st;
    st.push(s);

    while(!st.empty()){
        int top = st.top();
        st.pop();
        if(!visited[top]){
            cout << top << "  " << endl;
            visited[top] = 1;
            for(auto itr = adj[top].begin(); itr != adj[top].end(); ++itr){
                if(!visited[*itr]) st.push(*itr);
            }
        }
    }
}

int main(){
    Graph g(7);
    g.addEdge(1,2);
    g.addEdge(1,3);
    g.addEdge(2,4);
    g.addEdge(2,5);
    g.addEdge(3,6);
    g.addEdge(3,7);

    cout << "traversing starting from node" << 1 << " as source node using dfs is:" << endl;
    g.DFS(1);
    return 0;
}


