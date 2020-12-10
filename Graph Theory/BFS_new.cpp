#include <bits/stdc++.h>
using namespace std;

class Graph{
    vector<vector<int> > Edge;
    vector<unsigned char> visited;
public:
    Graph(int v){
        Edge.resize(v+1);
        visited.resize(v+1);
    }

    void add_edge(int u, int v){
        Edge[u].push_back(v);
    }

    void BFS(int s){
        for(auto i: visited){
            i = false;
        }

        list<int> q;
        visited[s] = true;
        q.push_back(s);

        while(!q.empty()){
            s = q.front();
            cout << s << "  ";
            q.pop_front();

            for(auto itr: Edge[s]){
                if(!visited[itr]){
                    visited[itr] = true;
                    q.push_back(itr);
                }
            }
        }
    }

};


// driver function
int main(){
    FILE *inp = freopen("inbfs.txt", "r", stdin);
    Graph g(11);
    int x, y;
    while(scanf("%d%d", &x, &y)==2){
        g.add_edge(x, y);
    }
    g.BFS(7);
    fclose(inp);
    return 0;
}
