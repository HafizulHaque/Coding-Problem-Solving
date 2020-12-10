#include <bits/stdc++.h>
int G[200][200];
using namespace std;

bool isBipartite(int V, int src){
    int colorArr[V];
    for (int i = 0; i < V; ++i)
        colorArr[i] = -1;

    colorArr[src] = 1;

    queue <int> q;
    q.push(src);

    while (!q.empty()){
        int u = q.front();
        q.pop();

        for (int v = 0; v < V; ++v){
            if (G[u][v] && colorArr[v] == -1){
                colorArr[v] = 1 - colorArr[u];
                q.push(v);
            }
            else if (G[u][v] && colorArr[v] == colorArr[u])
                return false;
        }
    }
    return true;
}

// Driver program
int main(){
    //FILE *inp = freopen("A.txt", "r", stdin);
    int n, q, u, v;
    while(scanf("%d", &n)==1){

        if(n==0) break;

        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                 G[i][j] = 0;
            }
        }

        scanf("%d", &q);
        for(int i = 0; i < q; ++i){
            scanf("%d%d", &u, &v);
            G[u][v] = 1;
            G[v][u] = 1;
        }

        isBipartite(n, 0) ? cout << "BICOLORABLE.\n" : cout << "NOT BICOLORABLE.\n";
    }
    //fclose(inp);
    return 0;
}
