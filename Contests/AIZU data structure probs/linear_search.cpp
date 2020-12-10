// accepted

#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *inp = freopen("in.txt", "r", stdin);
    int n, q;
    cin>>n;
    long arr[n];
    for(int i = 0; i < n; ++i) cin>>arr[i];
    cin>>q;
    long query[q];
    for(int i = 0; i < q; ++i) cin>>query[i];
    int cnt = 0;
    for(int i = 0; i < q; ++i){
        for(int j = 0; j < n; ++j){
            if(arr[j]==query[i]){
                cnt++;
                break;
            }
        }
    }
    cout << cnt << endl;
    //fclose(inp);
    return 0;
}
