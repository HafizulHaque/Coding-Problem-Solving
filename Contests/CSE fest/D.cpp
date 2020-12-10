#include <bits/stdc++.h>
using namespace std;

class Graph{
    int V;
    list<int> *adj;
public:
    Graph(int V);
    void addEdge(int v, int w);
    void longestPathLength();
    pair<int, int> bfs(int u);
};

Graph::Graph(int V){
    this->V = V;
    adj = new list<int>[V+1];
}

void Graph::addEdge(int v, int w){
    adj[v].push_back(w);
    adj[w].push_back(v);
}

pair<int, int> Graph::bfs(int u){
    int dis[V+1];
    memset(dis, -1, sizeof(dis));
    queue<int> q;

    q.push(u);
    dis[u] = 0;
    while(!q.empty()){
        int t = q.front();
        q.pop();

        for(auto itr = adj[t].begin(); itr != adj[t].end(); ++itr){
            int v = *itr;
            if(dis[v]==-1){
                q.push(v);
                dis[v] = dis[t] + 1;
            }
        }
    }

    int maxDis = 0;
    int nodeId;

    for(int i = 0; i <= V; ++i){
        if(dis[i]>maxDis){
            maxDis = dis[i];
            nodeId = i;
        }
    }
    return make_pair(nodeId, maxDis);
}

void Graph::longestPathLength(){
    pair<int, int> t1, t2;
    t1 = bfs(0);
    t2 = bfs(t1.first);
    cout << t2.first << endl;
}

int main(){
    int N;
    cin>>N;
    Graph g(N);
    int a, b;
    for(int i = 1; i <= N-1; ++i){
        cin>>a>>b;
        g.addEdge(a, b);
    }
    g.longestPathLength();
    return 0;
}
