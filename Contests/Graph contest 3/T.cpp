#include <bits/stdc++.h>
using namespace std;

pair<int , int> starting_pos, ending_pos;
int level[N+1][N+1];
int visited[N+1][N+1];
int x[] = {0, 0, 1, -1};
int y[] = {1, -1, 0, 0};


bool isSafe(int x, int y, int m, int n){
    return ((x>=0&&x<m)&&(y>=0&&y<n));
}

void _bfs(int m, int n, visited[][const A], int level[][const B] ){
    queue<pair<int, int> > q;
    visited[starting_pos.first][ending_pos.second] = 1;
    level[starting.first][starting.second] = 0;
    q.push(starting_pos);

    while(!q.empty()){
        int x_pos, y_pos;
        x_pos = q.front().first;
        y_pos = q.front().second;
        q.pop();

        for(int i = 0; i < 4; i++){
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
    int m, n;
    while(scanf("%d%d", &m, &n)==2){
        if(m==0&&m==0) break;

        int grid[m][n];
        for(int i = 0; i < m; ++i)
            for(int j = 0; j < n; ++j)
                grid[i][j] = 0;

        int r, row, cols, col;
        scanf("%d", &r);
        for(int i = 0; i < r; ++i){
            scanf("%d%d", &row, &cols){
                for(int j = 0; j < cols; ++j){
                    scanf("%d", &col);
                    grid[row][col] = 1;
                }
            }
        }
        int a, b;
        scanf("%d%d", &a, &b);
        starting_pos = make_pair(a, b);
        scanf("%d%d", &a, &b);
        ending_pos = make_pair(a, b);

        _bfs();
        level[queen_pos.first][queen_pos.second]);
    }
    return 0;
}
