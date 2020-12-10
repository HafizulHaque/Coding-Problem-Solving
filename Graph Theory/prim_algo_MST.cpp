#include <bits/stdc++.h>
using namespace std;
#define INF 0x3f3f3f3f
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
    adj = new vector<iPair>[V];   // makes a list of pair of two int of size V
}

void Graph::addEdge(int u, int v, int w){
    adj[u].push_back(make_pair(v, w));     // for each node - node on other side connected by
    adj[v].push_back(make_pair(u, w));    //  each edge and the cost pair is stored on each list
}

void Graph::primMST(){
    priority_queue<iPair, vector<iPair>, greater<iPair> > pq;   // min-heap priority queue
    int src = 0;
    vector<int> key(V, INF);    // vector of size v initialized with INF - for keys
    vector<int>parent(V, -1);   // to store parent array which in turn store MST
    vector<bool>inMST(V, false);// to keep track of vertices included in MST

    pq.push(make_pair(0, src));
    key[src] = 0;

    while(!pq.empty()){
        int u = pq.top().second;
        pq.pop();
        inMST[u] = true;

        vector<iPair>::iterator i;
        for(i = adj[u].begin(); i != adj[u].end(); ++i){
            int v = (*i).first;
            int weight = (*i).second;

            if(inMST[v]==false && key[v] > weight){
                key[v] = weight;
                pq.push(make_pair(key[v], v));
                parent[v] = u;
            }
        }
    }
    //print
    for(int i = 1; i < V; ++i)
        printf("%d - %d\n", parent[i], i);
}

int main(){
    FILE *inp = freopen("MST.txt", "r", stdin);
    int V = 9;
    int a, b, w;
    Graph g(V);
    while(scanf("%d%d%d", &a, &b, &w)==3){
        g.addEdge(a, b, w);
    }

    g.primMST();

    fclose(inp);
    return 0;
}
