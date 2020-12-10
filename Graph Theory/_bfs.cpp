#include <bits/stdc++.h>
using namespace std;
#define N 10          // no of Nodes
int visited[N+1];     // 0 for not visited, 1 for visited
vector<int>edge[N+1]; // edge representing adjacency list

int bfs(int root){
    queue<int>q;
    vector<int>::iterator itr;

    visited[root] = 1;
    q.push(root);

    while(!q.empty()){
        int item = q.front();
        cout<< item << "  ";
        q.pop();

        for(auto itr = edge[item].begin(); itr != edge[item].end(); ++itr){
            if(!visited[*itr]){
                visited[*itr] = 1;
                q.push(*itr);
            }
        }
    }
    printf("\n");
}

int main(){

    FILE *in = freopen("input.txt", "r", stdin);
    int a, b;

    while(scanf("%d%d", &a, &b)==2){
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    bfs(2);
    fclose(in);
    return 0;
}
