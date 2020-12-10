#include <bits/stdc++.h>
using namespace std;
#define N 11

int main(){
    FILE *inp = freopen("inbfs.txt", "r", stdin);
    vector<int> pairs[N+1];
    int x, y;
    while(scanf("%d%d", &x, &y)==2){    // input the edge pairs
        pairs[x].push_back(y);
    }

    int visited[N];
    memset(visited, 0, sizeof(visited));    // visited indicating array

    queue<int> q;           // queue to add nodes as order

    int startingNode = 3;
    visited[startingNode] = 1;     // first add a certain starting node visited
    q.push(startingNode);

    vector<int>::iterator itr;      // iterator for traversing child nodes

    while(!q.empty()){
        int a = q.front();
        printf("%d ", q.front());
        q.pop();

        for(itr = pairs[a].begin(); itr != pairs[a].end(); ++itr){
            if(visited[*itr]==0){
                visited[*itr] = 1;
                q.push(*itr);
            }
        }
    }
    fclose(inp);
    return 0;
}
