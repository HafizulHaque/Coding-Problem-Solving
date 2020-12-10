// accepted

#include <stdio.h>
#include <math.h>

int main(){
    //FILE *inp = freopen("in.txt", "r", stdin);
    int n, k = -1;
    scanf("%d", &n);
    if(!(n%3)){
        printf("2\n");
        return 0;
    }
    if(!(n%4)){
        printf("3\n");
        return 0;
    }
    while(!(n%2)){
        n /= 2;
    }
    k = n-1;
    int sq = sqrt(n+0.1);
    for(int i = 4; i <= sq+1 ; ++i){
        if(!(n%i)){
            k = i-1;
            break;
        }
    }
    printf("%d\n", k);
    //fclose(inp);
    return 0;
}
