#include <bits/stdc++.h>
using namespace std;
#define N 10
map<int, int>node;
vector<int>edge[N+1];
int level[N+1];
int cost[N+1];
int visited[N+1];   // 0 for unvisited 1 for visited.


void bfs(int source){
    map<int, int>::iterator itr;
    queue<int>q;
    itr = find(node.begin(), node.end(), source);

    visited[itr->first] = 1;
    q.push(itr->first);

}

int main(){
    int a, b;
    printf("Enter %d Nodes : ", N);
    for(int i = 1; i <= N; ++i){
        scanf("%d", &a);
        node.insert(make_pair(i, a));
    }

    while(scanf("%d%d", &a, &b)==2){
        edge[a].push_back(b);
        edge[b].push_back(a);
    }

    bfs(100);
    return 0;
}
