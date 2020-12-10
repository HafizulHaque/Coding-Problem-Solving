#include <bits/stdc++.h>
using namespace std;
#define N 26
int x[] = {0, 1, -1};
int y[] = {0, 1, -1};

int visited[N][N];
int px[N][N];

int main(){
    FILE *inp = freopen("E.txt", "r", stdin);
    int n;

    while(scanf("%d", &n)==1){
        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                scanf("%1d", &px[i][j]);
            }
        }

        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                visited[i][j] = 0;
            }
        }
    }
    fclose(inp);
    return 0;
}
