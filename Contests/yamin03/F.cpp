// accepted

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1300000
int prime[N+1];    // 0 prime 1 not prime

ll seive(){
    prime[0]=prime[1]=1;
    for(int i = 2; i*i <= N; ++i){
        if(!prime[i]){
            for(int j = 2*i; j <= N; j += i) prime[j] = 1;
        }
    }
}

int main(){
    seive();
    int n, prime_cnt = 0;
    scanf("%d", &n);
    int index = 2;
    for(int i = 1;  ; ++i){
        if(!prime[i]){
            printf("%d ", i);
            prime_cnt++;
        }
        if(prime_cnt>=n) break;
    }
    printf("\n");
    return 0;
}
