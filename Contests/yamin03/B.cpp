// accepted

#include <bits/stdc++.h>
using namespace std;
#define N 100000
int isPresent[N+1];
int numbers[N+2];
int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    int n, q, l, addval;
    scanf("%d%d", &n, &q);
    for(int i = 1; i <= n; ++i) scanf("%d", &numbers[i]);
    numbers[n+1] = 0;
    for(int i = n; i >= 1; --i){
        addval = isPresent[numbers[i]]? 0:1;
        isPresent[numbers[i]] = 1;
        numbers[i] = numbers[i+1]+addval;
    }
    while(q--){
        scanf("%d", &l);
        printf("%d\n", numbers[l]);
    }
    return 0;
}
