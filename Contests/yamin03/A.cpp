// accepted

#include <bits/stdc++.h>
using namespace std;
pair<int, int> points[101];
int visited[101];
int edges[101][101];

void dfs(int s, int n){
    queue<int>q;
    q.push(s);
    while(!q.empty()){
        int item = q.front();
        q.pop();
        visited[item] = 1;
        for(int i = 1; i <= n; ++i){
            if(edges[item][i]&&!visited[i]) q.push(i);
        }
    }
    return;
}


int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    int n, x, y, disJoint = 0;
    cin>>n;
    for(int i = 1; i <= n; ++i){
        cin>>points[i].first>>points[i].second;
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            if(points[i].first==points[j].first||points[i].second==points[j].second){
                edges[i][j] = edges[j][i] = 1;
            }
        }
    }
    for(int i = 1; i <= n; ++i){
        if(!visited[i]){
            dfs(i, n);
            disJoint++;
        }
    }
    cout << disJoint-1 << endl;
    return 0;
}
