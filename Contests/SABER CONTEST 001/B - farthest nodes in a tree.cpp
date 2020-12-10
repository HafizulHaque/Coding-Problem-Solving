// accepted

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>

class Tree{
    int N;
    list<pii> *edges;
public:
    Tree(int n);
    void addEdge(int u, int v, int w);
    pii bfs(int n);
    int maxLengthPath();
};

Tree::Tree(int n){
    this->N = n;
    edges = new list<pii>[N];
}

void Tree::addEdge(int u, int v, int w){
    edges[u].push_back(make_pair(v, w));
    edges[v].push_back(make_pair(u, w));
}

pii Tree::bfs(int n){
    int dis[N];
    list<pii>::iterator itr;
    memset(dis, -1, sizeof(dis));
    queue<int>q;
    q.push(n);
    dis[n] = 0;
    while(!q.empty()){
        int t = q.front();
        q.pop();
        for(itr = edges[t].begin(); itr != edges[t].end(); ++itr){
            int neigh = itr->first;
            int weight = itr->second;

            if(dis[neigh] == -1){
                q.push(neigh);
                dis[neigh] = dis[t] + weight;
            }
        }
    }

    int maxDis = 0;
    int nodeId = 0;

    for(int i = 0; i < N; ++i){
        if(maxDis<dis[i]){
            maxDis = dis[i];
            nodeId = i;
        }
    }
    return make_pair(nodeId, maxDis);
}

int Tree::maxLengthPath(){
    pii res = bfs(0);
    res = bfs(res.first);
    return res.second;
}


int main(){
    // driver program
    //FILE *inp = freopen("B.txt", "r", stdin);
    int test_case;
    cin>>test_case;
    for(int i = 1; i <= test_case; ++i){
        int n, u, v, w;
        cin>>n;
        Tree tree(n);
        for(int j = 1; j < n; ++j){
            cin>>u>>v>>w;
            tree.addEdge(u, v, w);
        }
        cout << "Case " << i << ": " << tree.maxLengthPath() << endl;
    }
    //fclose(inp);
    return 0;
}
