#include <bits/stdc++.h>
using namespace std;
#define N 8
#define pii pair<int, int>
pii home, a, b, c;
//int level[N+1][N+1];
//int visited[N+1][N+1];
int x[] = {1, -1, 0, 0};
int y[] = {0, 0, 1, -1};


bool isSafe(int x, int y){
    return ((x>=1&&x<=N)&&(y>=1&&y<=N));
}

int _bfs(pii source, pii destination){
    queue<pii> q;
    visited[knight_pos.first][knight_pos.second] = 1;
    level[knight_pos.first][knight_pos.second] = 0;
    q.push(knight_pos);

    while(!q.empty()){
        int x_pos, y_pos;
        x_pos = q.front().first;
        y_pos = q.front().second;
        q.pop();

        for(int i = 0; i < 8; i++){
            int X = x_pos+x[i];
            int Y = y_pos+y[i];
            if(isSafe(X,Y)&&(visited[X][Y]==0)){
                visited[X][Y] = 1;
                level[X][Y] = level[x_pos][y_pos]+1;
                q.push(make_pair(X,Y));
                if(X==queen_pos.first&&Y==queen_pos.second)
                    return;
            }
        }
    }
    return;
}

int main(){
    //int a, b;
    //printf("Enter position of knight on Chess Board : ");
    //scanf("%d%d", &a, &b);
    //knight_pos = make_pair(a, b);
    //printf("Enter position of queen on Chess Board  : ");
    //scanf("%d%d", &a, &b);
    //queen_pos = make_pair(a, b);
    int m, n;
    cin>>m>>n;
    int level[m][n];
    int visited[m][n];
    char pos[m][n];
    for(int i = 0; i < m; ++i){
        for(int j = 0; j < n; ++j){
            cin>>pos[m][n];
            if(pos[i][j]=='#') visited[i][j] = 1;
            if(pos[i][j]=='a') a = make_pair(i, j);
            if(pos[i][j]=='b') b = make_pair(i, j);
            if(pos[i][j]=='c') c = make_pair(i, j);
            if(pos[i][j]=='h') h = make_pair(i, j);
        }
    }

    _bfs();

    return 0;
}

