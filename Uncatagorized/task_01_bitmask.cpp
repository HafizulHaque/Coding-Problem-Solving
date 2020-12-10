// you have an integer A with some value. print the integer which have-
//       bit pattern as a except it has all bits 0 within 4th to 23rd position

#include <bits/stdc++.h>
using namespace std;

int main(){
    int num;
    int startIndex = 4, endIndex = 23;
    int n = endIndex-startIndex+1;
    int x;
    while(scanf("%d", &num)==1){
        x = ~(num&0);
        x<<=n;
        for(int i = 0; i < 4; ++i){
            x = (x<<1)|1;
        }

        num = (num&x);
        printf("manipulated number is : %d\n", num);
    }
    return 0;
}
