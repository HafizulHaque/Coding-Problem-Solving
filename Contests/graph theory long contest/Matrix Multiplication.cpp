#include <bits/stdc++.h>
using namespace std;
#define ROWSA 3
#define COLSA 3
#define ROWSB 3
#define COLSB 3

int main(){
    int A[ROWSA][COLSA], B[ROWSB][COLSB];

    //input matrix A, B
    for(int i = 0; i < ROWSA; ++i){
        for(int j = 0; j < COLSA; ++j)
            cin>>A[i][j];
    }
    for(int i = 0; i < ROWSB; ++i){
        for(int j = 0; j < COLSB; ++j)
            cin>>B[i][j];
    }

    // MULTIPLICATION POSSIBLE IF COLSA == ROWSB

    int RES[ROWSA][COLSB];
    memset(RES, 0, sizeof(RES));

    for(int i = 0; i < ROWSA; ++i){
        for(int j = 0; j < COLSA; ++j){
            int sum = 0;
            for(int k = 0; k < COLSB; ++k){
                sum += A[i][j]*B[j][k];
            }
            RES[i][k] = sum;
        }
    }

    for(int i = 0; i < ROWSA; ++i){
        for(int j = 0; j < COLSB; ++j){
            cout << RES[i][j] << "  ";
        }
        cout << endl;
    }
    return 0;

}
