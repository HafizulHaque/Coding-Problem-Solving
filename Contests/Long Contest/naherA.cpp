#include <bits/stdc++.h>
using namespace std;

int main(){
    int test, n, source, destinaton;
    cin>>test;
    while(t--){
        cin>>n>>source>>destination;
        list<int> adj[n+1];
        int u, v;
        for(int i = 1; i < n; ++i){
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
    }
    for()
}
