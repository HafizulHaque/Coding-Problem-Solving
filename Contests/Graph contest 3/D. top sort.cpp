#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;
    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);
    void addEdge(int v, int w);
    void topologicalSort();
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
}

void Graph::topologicalSortUtil(int v, bool visited[],stack<int> &Stack){
    visited[v] = true;
    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);

    // Push current vertex to stack which stores result
    Stack.push(v);
}

void Graph::topologicalSort()
{
    stack<int> Stack;
    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        topologicalSortUtil(i, visited, Stack);

    while (Stack.empty() == false){
        cout << Stack.top()+1 << " ";
        Stack.pop();
    }
    cout << endl;
}

// Driver program
int main()
{
    //FILE *inp = freopen("D.txt", "r", stdin);
    int n, m, u, v;
    while(scanf("%d%d", &n, &m)==2){
        if(n==0&&m==0) break;
        Graph g(n);
        for(int i = 0; i < m; ++i){
            scanf("%d%d", &u, &v);
            g.addEdge(u-1, v-1);
        }
        g.topologicalSort();
    }
    //fclose(inp);
    return 0;
}
