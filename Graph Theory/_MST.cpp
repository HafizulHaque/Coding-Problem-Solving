#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> iPair;

class Graph{
    int V;
    vector<iPair> *adj;
public:
    Graph(int V);
    void addEdge(int u, int v, int w);
    void primMST();

};

Graph::Graph(int V){
    this->V = V;
    adj = new vector<iPair>[V];
}

void Graph::addEdge(int u, int v, int w){
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}

void primMST(int src){
    priority_queue<iPair, vector<iPair>, greater<iPair> > pq;
    vector<int> key(V, INT_MAX);    // for comparing the lowest cost edge connected to a node
    vector<int> parent(V, -1);      // for storing parent node of a node in spanning tree
    vector<unsigned char> inMST(V, 0);  // to check weather a node is already in MST or not

    pq.push(make_pair(0, src)); // weight-node pair
    key[src] = 0;

    vector<iPair>::iterator itr;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();

        for(itr = adj[u].begin(); itr != adj[u].end(); ++itr){
            int v = (*itr)first;
            int weight = (*itr).second;

            if(inMST[v]==false && weight<key[v]){
                key[v] = weight;
                pq.push_back(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
}

//driver program
int main(){
    Graph g(9);
    int a, b, c;
    while(scanf("%d%d%d", &a, &b, &c)==3){
        g.addEdge(a, b, c);
    }
    g.primMST();
    return 0;
}
