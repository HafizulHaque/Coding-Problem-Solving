// take the cut value of 3rd to 7th bit of the bit string of the given number

#include <bits/stdc++.h>
using namespace std;

int main(){

    int n = 187;  // 0000 0000 1011 1011      [10111 = 23]
    int p = 7-3+1;
    int x = 0;

    for(int i = 0; i < p; ++i){
        x = (x<<1)|1;
    }
    x<<=3;

    int result = x&n;
    result>>=3;

    printf("result : %d\n", result);
    return 0;
}
