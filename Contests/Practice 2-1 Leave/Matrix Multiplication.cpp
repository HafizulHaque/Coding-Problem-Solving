#include <bits/stdc++.h>
using namespace std;
#define ROWSA 3
#define COLSA 3
#define ROWSB 3
#define COLSB 3

int main(){
    // input from file
    FILE *file = freopen("input.txt", "r", stdin);

    // declaration of matrix
    int A[ROWSA][COLSA], B[ROWSB][COLSB];

    int i, j, k;

    //input matrix A, B
    for(i = 0; i < ROWSA; ++i){
        for(j = 0; j < COLSA; ++j)
            cin>>A[i][j];
    }
    for(i = 0; i < ROWSB; ++i){
        for(j = 0; j < COLSB; ++j)
            cin>>B[i][j];
    }

    // MULTIPLICATION POSSIBLE IF COLSA == ROWSB

    int RES[ROWSA][COLSB];
    //memset(RES, 0, sizeof(RES));

    for(i = 0; i < ROWSA; ++i){
        for(j = 0; j < COLSB; ++j){
            int sum = 0;
            for(k = 0; k < COLSA; ++k){
                sum += A[i][k]*B[k][j];
            }
            RES[i][j] = sum;
        }
    }

    for(int i = 0; i < ROWSA; ++i){
        for(int j = 0; j < COLSB; ++j){
            cout << RES[i][j] << "  ";
        }
        cout << endl;
    }

    fclose(file);
    return 0;

}
