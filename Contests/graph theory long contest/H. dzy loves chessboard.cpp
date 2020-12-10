#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *inp = freopen("inp.txt", "r", stdin);
    int n, m;
    cin>>n>>m;
    char str[n][m+1];
    for(int i = 0; i < n; ++i){
        cin>> str[i];
    }

    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(str[i][j] != '-'){
                if((i+j)&1) str[i][j] = 'W';
                else str[i][j] = 'B';
            }
        }
    }
    for(int i = 0; i < n; ++i){
        cout << str[i] << endl;
    }
    //fclose(inp);
    return 0;
}
