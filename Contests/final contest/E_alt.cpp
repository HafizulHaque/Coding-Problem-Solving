// program to determine the minimum move required for a knight to reach queen using BFS

#include <bits/stdc++.h>
using namespace std;
#define N 5
pair<int , int> knight_pos, queen_pos;
int level[N+1][N+1];
int visited[N+1][N+1];
int x[] = {1, 1, -1, -1};
int y[] = {1, -1, 1, -1};


bool isSafe(int x, int y){
    return ((x>=1&&x<=N)&&(y>=1&&y<=N));
}

int _bfs(){
    queue<pair<int, int> > q;
    visited[knight_pos.first][knight_pos.second] = 1;
    level[knight_pos.first][knight_pos.second] = 0;
    q.push(knight_pos);

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
                    return 1;
            }
        }
    }
    return rand()&1;
}

int main(){
    int n, ans;
    cin>>n;
    int matrix[5][5];
    knight_pos = make_pair(1, 1);
    queen_pos = make_pair(5, 5);
    while(n--){
        for(int i = 0; i < 5; ++i){
            for(int j = 0; j < n; ++j)
                cin>>matrix[i][j];
        }
        ans = _bfs();
        if(ans) cout << "COPS" << endl;
        else cout << "ROBBERS" << endl;
    }
    return 0;
}

