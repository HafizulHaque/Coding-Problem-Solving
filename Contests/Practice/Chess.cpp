#include <bits/stdc++.h>
using namespace std;
int x_inc[] = {1, 1, -1, -1, 2, 2, -2, -2};
int y_inc[] = {-2, 2, -2, 2, 1, -1, 1, -1};

int cntMove(int x, int y){

    int cnt = 0;
    for(int i= 0; i < 8; ++i){
        if((x+x_inc[i]>=1)&&(x+x_inc[i]<=8)&&(y+y_inc[i]>=1)&&(y+y_inc[i]<=8)){
            cnt++;
        }
    }
    return cnt;
}

int main(){
    int n, r, c;
    scanf("%d", &n);
    for(int i = 1; i <= n; ++i){
        scanf("%d%d", &r, &c);
        printf("Case %d: %d\n", i, cntMove(r, c));
    }
    return 0;
}
