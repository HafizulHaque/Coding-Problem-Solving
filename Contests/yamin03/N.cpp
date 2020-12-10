// accepted

#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    ll col[3], ans = 0, temp, _max = 0;
    for(int i = 0; i < 3; ++i) scanf("%lld", &col[i]);
    sort(col, col+3);
    temp = col[0]/3;
    if(col[0]>10){
        temp = col[0]-10;
        ans = temp;
        col[0] -= temp;
        col[1] -= temp;
        col[2] -= temp;
    }
    for(int i = col[0]; i >= 0; --i){
        temp = i+(col[0]-i)/3+(col[1]-i)/3+(col[2]-i)/3;
        _max = max(_max, temp);
    }
    ans += _max;
    printf("%lld\n", ans);
    return 0;
}
