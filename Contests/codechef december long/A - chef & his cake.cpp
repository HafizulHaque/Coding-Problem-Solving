#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    int t;
    scanf("%d\n", &t);
    while(t--){
        int r, c;
        scanf("%d%d\n", &r, &c);
        char cake[r+1][c+1];
        int prinRed=0, prinGreen=0, secRed=0, secGreen=0;
        for(int i = 1; i <= r; ++i){
            for(int j = 1; j <= c; j++){
                scanf("%c", &cake[i][j]);
                if((i+j)&1){
                    // secondary
                    if(cake[i][j]=='R') secRed++;
                    else if(cake[i][j]=='G') secGreen++;
                }
                else{
                    // primary
                    if(cake[i][j]=='R') prinRed++;
                    else if(cake[i][j]=='G') prinGreen++;
                }
            }
            scanf("\n");
        } // input & computation ends

        int minCost;
        if((r*c)&1){
            if(prinRed+secRed>prinGreen+secGreen){
                minCost = 8*(prinGreen);
            }
            else{
                minCost = 8*(prinRed);
            }
        }
        else{
            minCost = 8*min(prinGreen, prinRed);
        }
        cout << minCost << endl;
    }
    return 0;
}
