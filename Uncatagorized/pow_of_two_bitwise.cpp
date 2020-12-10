// determine weather a number is pow of 2 or not

#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n)==1){
        if(!(n&(n-1)))
            printf("Pow of 2\n");
        else
            printf("not Pow of 2\n");
    }
    return 0;
}
