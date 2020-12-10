#include <bits/stdc++.h>
using namespace std;
#define N 10000
unsigned char prime[10002];   // 0 means prime ,1 means non-prime

int main(){
    memset(prime, 0, sizeof(prime));
    prime[0] = 1;
    prime[1] = 1;

    for(int i = 4; i <= N; i += 2)
        prime[i] = 1;

    for(int i = 3; i <= N ; i += 2){
        if(!prime[i]){
            for(int j = i*i; j <= N; j += i)
                prime[j] = 1;
        }
    }

    for(int i = 0; i <= N; ++i){
        if(!prime[i])
            printf("%d  ", i);
    }
    printf("\n");
    return 0;
}
