// accepted

#include <bits/stdc++.h>
using namespace std;
long arr[150001];

int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    long n, k, num, temp, _min = 100000000, index = 1;
    scanf("%ld%ld", &n, &k);
    for(int i = 1; i <= n; ++i){
        scanf("%ld", &num);
        arr[i] = arr[i-1];
        arr[i] += num;
    }
    for(int i = 1; i <= n-k+1; ++i){
        temp = arr[i+k-1]-arr[i-1];
        if(temp<_min){
            _min = temp;
            index = i;
        }
    }
    printf("%ld\n", index);
    return 0;
}
