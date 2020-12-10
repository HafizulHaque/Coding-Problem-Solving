// accepted

#include <bits/stdc++.h>
using namespace std;
int arr[100002];
char str[100002];
int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    int q, a, b, len;
    scanf("%s\n", str);
    len = strlen(str);
    for(int i = 2; i <= len; ++i){
        arr[i] = str[i-2]==str[i-1]? 1 : 0;
        arr[i] += arr[i-1];
    }
    scanf("%d\n", &q);
    while(q--){
        scanf("%d%d", &a, &b);
        printf("%d\n", arr[b]-arr[a]);
    }
    return 0;
}
