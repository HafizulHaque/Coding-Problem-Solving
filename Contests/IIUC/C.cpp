#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *inp = freopen("inp.txt", "r", stdin);
    int n, q;
    while(1){
        scanf("%d", &n);
        if(!n) break;
        scanf("%d", &q);
        int arr[n+1];
        for(int i = 1; i <= n; ++i) scanf("%d", &arr[i]);
        int a, b;
        for(int i = 0; i < q; ++i){
            scanf("%d%d", &a, &b);
            int _max = 0, cnt = 1;
            int prev = arr[a];
            for(int j = a+1; j <= b; ++j){
                if(arr[j]==prev) cnt++;
                else{
                    _max = max(cnt, _max);
                    cnt = 1;
                }
                prev = arr[j];
            }
            _max = max(_max, cnt);
            printf("%d\n", _max);
        }
    }
    //fclose(inp);
    return 0;
}
