#include<bits/stdc++.h>
using namespace std;

int main(){
    int n;
    while(scanf("%d", &n)==1){
        if(n&1)
            printf("odd number\n");
        else
            printf("even number\n");
    }
    return 0;
}
