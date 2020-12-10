// accepted

#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *inp = freopen("in.txt", "r", stdin);
    int n, size, cnt, mid;
    scanf("%d", &n);
    int arr[n];
    for(int i = 0; i < n; ++i) scanf("%d", &arr[i]);
    cnt = n;
    mid = n/2;
    sort(arr, arr+n);
    for(int i = 0; i < n/2; ++i){
        while(1){
            if(mid<n&&arr[i]*2<=arr[mid]){
                cnt--;
                mid++;
                break;
            }
            mid++;
            if(mid>=n) goto node;
        }
    }
    node:
    cout << cnt << endl;
    //fclose(inp);
    return 0;
}
