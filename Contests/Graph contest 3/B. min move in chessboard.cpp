// program to determine the minimum move required for a knight to reach queen using BFS

#include <bits/stdc++.h>
using namespace std;
#define N 8
pair<int , int> init_pos, final_pos;
int level[N+1][N+1];
int visited[N+1][N+1];
int x[] = {1, 1, -1, -1, 2, 2, -2, -2};
int y[] = {2, -2, 2, -2, 1, -1, 1, -1};


bool isSafe(int x, int y){
    return ((x>=1&&x<=N)&&(y>=1&&y<=N));
}

void _bfs(){
    queue<pair<int, int> > q;

    for(int i = 1; i <= N; ++i){
        for(int j = 1; j <= N; ++j){
            visited[i][j] = 0;
            level[i][j] = 0;
        }
    }

    visited[init_pos.first][init_pos.second] = 1;
    level[final_pos.first][final_pos.second] = 0;
    q.push(init_pos);

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
                if(X==final_pos.first&&Y==final_pos.second)
                    return;
            }
        }
    }
    return;
}

int main(){
    //FILE *inp = freopen("B.txt", "r", stdin);

    int a, b;
    char firstString[5], secondString[5];
    while(scanf("%s%s", firstString, secondString)==2){
        a = firstString[0]-96;
        b = firstString[1]-48;
        init_pos = make_pair(a, b);
        a = secondString[0]-96;
        b = secondString[1]-48;
        final_pos = make_pair(a, b);
        _bfs();
        printf("To get from %s to %s takes %d knight moves.\n", firstString, secondString, level[final_pos.first][final_pos.second]);
    }
    //fclose(inp);
    return 0;
}

