// accepted
#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    int n, m, q, a, b;
    char ch;
    scanf("%d%d%d", &n, &m, &q);
    int mat[n+1][m+1];
    int row[n+1],col[m+1];
    for(int i = 1; i <= n; ++i) row[i] = i;
    for(int i = 1; i <= m; ++i) col[i] = i;

    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= m; ++j) scanf("%d", &mat[i][j]);
    }
    scanf("\n");
    for(int i = 0; i < q; ++i){
        scanf("%c%d%d\n", &ch, &a, &b);
        if(ch=='r'){
            row[a] ^= row[b];
            row[b] ^= row[a];
            row[a] ^= row[b];
        }
        else if(ch=='c'){
            col[a] ^= col[b];
            col[b] ^= col[a];
            col[a] ^= col[b];
        }
        else if(ch=='g'){
            printf("%d\n",mat[row[a]][col[b]]);
        }
    }
    //fclose(inp);
    return 0;
}
