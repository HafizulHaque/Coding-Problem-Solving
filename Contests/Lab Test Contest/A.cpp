#include <bits/stdc++.h>
using namespace std;
#define N 6
int arr[N][N];
int x[] = {-1, 1, 0, -1, 1, 0, 0};
int y[] = {1, 1, 1, -1, -1, -1, 0};

int getsum(int a, int b){
    int s = 0;
    for(int i = 0; i < 7; ++i)
        s += arr[a+y[i]][b+x[i]];
    return s;
}

int main(){
    int sum = 0;
    int max = 0;

    for(int i = 0; i < N; ++i)
        for(int j = 0; j < N; ++j)
            cin>>arr[i][j];

    for(int i = 1; i <= 4; ++i){
        for(int j = 1; j <= 4; ++j){
            sum = getsum(i, j);
            if(sum>max)
                max = sum;
        }
    }
    cout << max << endl;
    return 0;
}

