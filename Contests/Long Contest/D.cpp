// accepted

#include <bits/stdc++.h>
using namespace std;
#define N 8

int main(){
    //FILE *inp = freopen("in.txt", "r", stdin);
    char board[N][N];
    for(int i = 0; i < N; ++i){
        for(int j = 0; j < N; ++j){
            cin>>board[i][j];
        }
    }
    for(int i = 0; i < N; ++i){
        for(int j = 1; j < N; ++j){
            if(board[i][j-1]==board[i][j]){
                cout << "NO" << endl;
                //fclose(inp);
                return 0;
            }
        }
    }
    cout << "YES" << endl;
    //fclose(inp);
    return 0;
}
