// accepted
#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    ll cnt = 0, n;
    cin>>n;
    ll arr[n+1];
    for(int i = 1; i <= n; ++i) cin>>arr[i];
    sort(arr+1, arr+(n+1));
    for(int i = 1; i <= n; ++i) cnt += arr[i]<i? i-arr[i]:arr[i]-i;
    cout << cnt << endl;
    //fclose(inp);
    return 0;
}
