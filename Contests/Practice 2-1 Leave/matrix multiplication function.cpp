#include <bits/stdc++.h>
using namespace std;

int **mat_mul(int **a, int rowa, int cola, int **b, int rowb, int colb, int **res){
    int i, j, k;

    for(i = 0; i < rowa; ++i){
        for(j = 0; j < colb; ++j){
            for(k = 0; k < cola; ++k){
                res[i][j] += a[i][k]*b[k][j];
            }
        }
    }
    return res;
}

int **make_twoDarr(int **arr, int m, int n){
    arr = new int *[m];
    for(int i = 0; i < m; ++i)
        arr[i] = new int[n];

    for(int i = 0; i < m; ++i)
        for(int j = 0; j < n; ++j)
            arr[i][j] = 0;
    return arr;
}

int main(){

    // input from file
    FILE *file = freopen("input_mat_func.txt", "r", stdin);

    // variable declaration
    int i, j, k;
    int **a, **b, **res;
    int rowa, cola, rowb, colb, resrow, rescol;

    // 2d array (matrix) initialize & input

    cin>>rowa>>cola;                    // input size of a
    a = make_twoDarr(a, rowa , cola);   // initializing a
    for(i = 0; i < rowa; ++i){          // input matrix entries of a
        for(j = 0; j < cola; ++j)
            cin>>a[i][j];
    }
    cin>>rowb>>colb;                    // input size of b
    b = make_twoDarr(b, rowb , colb);   // initializing b
    for(i = 0; i < rowb; ++i){         // input matrix entries of b
        for(j = 0; j < colb; ++j)
            cin>>b[i][j];
    }

    resrow = rowa;                              // initialize result matrix row & col
    rescol = colb;
    res = make_twoDarr(res, rowa , colb);       // initializing the result matrix res

    //matrix multiplication
    res = mat_mul(a, rowa, rowb, b, rowb, colb, res);

    // print result
    for(i = 0; i < resrow; ++i){
        for(j = 0; j < rescol; ++j){
            cout << res[i][j] << "  ";
        }
        cout << endl;
    }

    // file close & return
    fclose(file);
    return 0;
}
