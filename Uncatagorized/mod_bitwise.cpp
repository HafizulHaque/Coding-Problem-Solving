// mod by power of 2

#include <bits/stdc++.h>
using namespace std;

int main(){
    // if P = 2^n  then N%P = N &(P-1);
    int n, d;
    while(scanf("%d%d", &n, &d)==2){
        printf("%d mod %d = %d\n", n, d, n&(d-1));
    }
    return 0;
}
