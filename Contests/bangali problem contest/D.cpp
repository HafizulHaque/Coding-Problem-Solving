// accepted

#include <bits/stdc++.h>
using namespace std;
#define i64 unsigned long long
#define P 1000000007

int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    int t, n;
    i64 num, ans;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        ans = 0;
        while(n--){
            scanf("%llu", &num);
            ans = ((ans%P)+(num%P))%P;
        }
        printf("%llu\n", ans);
    }
    return 0;
}
