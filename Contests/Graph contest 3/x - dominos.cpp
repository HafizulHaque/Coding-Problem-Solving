#include <bits/stdc++.h>
using namespace std;
int edge[10001][10001];
int dominos_count;

void dfs(int root, int n, int visited[]){
    if(visited[root]) return;
    visited[root] = 1;
    dominos_count++;
    for(int i = 1; i <= n; ++i){
        if(edge[root][i]&&(!visited[i])){
            visited[i] = 1;
            dominos_count++;
            dfs(i, n, visited);
        }
    }
}

int main(){
    //FILE *inp = freopen("x.txt", "r", stdin);
    int t;
    cin>>t;
    while(t--){
        int n, m, l;
        cin>>n>>m>>l;
        int visited[n+1];
        dominos_count = 0;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j){
                edge[i][j] = 0;
                visited[i] = 0;
            }

        int a, b;
        for(int i = 0; i < m; ++i){
            cin>>a>>b;
            edge[a][b]= 1;
        }
        int p;
        for(int i = 0; i < l; ++i){
           cin>>p;
           dfs(p, n, visited);
        }
        cout << dominos_count << endl;
    }
    //fclose(inp);
    return 0;
}
