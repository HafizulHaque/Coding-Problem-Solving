// accepted

#include <bits/stdc++.h>
using namespace std;
#define MAXN 2020
#define pii pair<int, int>
pii res[2];     // res[0] - black  , res[1] - white
long long maxDig[2]; // max principal dig, max secondary dig
long long board[MAXN][MAXN];
long long digOne[2*MAXN], digTwo[2*MAXN]; // principal diagonal , secondary diagonal

int main(){
    //FILE *inp = freopen("in.txt", "r", stdin);
    int n;
    long long total;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            scanf("%lld", &board[i][j]);
            digOne[i+j] += board[i][j];
            digTwo[i-j+n] += board[i][j];
        }
    }
    maxDig[0] = maxDig[1] = -1;
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            int color = (i+j)&1;
            total = digOne[i+j]+digTwo[i-j+n]-board[i][j];
            if(total>maxDig[color]){
                maxDig[color] = total;
                res[color].first = i;
                res[color].second = j;
            }
        }
    }
    if(res[0]>res[1]) swap(res[0], res[1]);
    cout << maxDig[0]+maxDig[1] << endl;
    cout << res[0].first << " " << res[0].second << " " << res[1].first << " " << res[1].second << endl;
    //fclose(inp);
    return 0;
}
