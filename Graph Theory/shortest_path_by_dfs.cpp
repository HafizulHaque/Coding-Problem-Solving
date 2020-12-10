#include <bits/stdc++.h>
using namespace std;
#define intPair vector<pair<int, int> >
int *taken;
vector<int> elements;

class Graph{
    int node;
    intPair *edge;
public:
    Graph();
    void addEdge(int a, int b, int w);
    void shortest_path();
};

Graph::Graph(int n){
    node = n;
    edge = new intPair(n);
    taken = new edge(n);
    memset(taken, 0, sizeof(taken));
}

void Graph::addEdge(int a, int b, int w){
    edge[a].push_back(make_pair(b, w));
    edge[b].push_back(make_pair(a, w));
}

void Graph::shortest_path(int startNode, int endNode){
    static int _min = INT_MAX;
    if(elements.size()==node){
        print();
        return;
    }

    for(auto itr = edge[startNode].begin(); itr != edge[startNode].end(); ++itr){

    }


    taken[startNode] = 1;

}

// driver program
int main(){
    // FILE *inp_file = freopen("ab.txt", "r", stdin);
    Graph g(10);
    int a, b, w;
    while(scanf("%d%d%d", &a, &b, &w)==3){
        g.addEdge(a, b, c);
    }
    shortest_path(0, 9);
    // fclose(inp_file);
    return 0;
}
