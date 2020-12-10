// accepted

#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *inp = freopen("in.txt", "r", stdin);
    int n, q, key;
    scanf("%d", &n);
    long arr[n];
    for(int i = 0; i < n; ++i) scanf("%ld", &arr[i]);
    scanf("%d", &q);
    int cnt = 0;
    for(int i = 0; i < q; ++i){
        scanf("%ld", &key);
        int low, mid, high;
        low = 0;
        high = n-1;
        while(low <= high){
            mid = low + (high-low)/2;
            if(arr[mid]==key){
                cnt++;
                break;
            }
            else if(arr[mid]<key) low = mid+1;
            else high = mid-1;
        }
    }
    printf("%d\n", cnt);
    //fclose(inp);
    return 0;
}
