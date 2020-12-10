#include <bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    FILE *inp = freopen("input.txt", "r", stdin);
    int n, s;
    cin>>n>>s;
    int _min[s+1];
    int v[n+1];
    for(int i = 1; i <= n; ++i) cin>>v[i];
    //algorithm
    for(int i = 0; i <= s; ++i) _min[i] = INT_MAX-1;
    _min[0] = 0;
    for(int i = 1; i <= s; ++i){
        for(int j = 1; j <= n; ++j){
            if(v[j]<=i&&_min[i-v[j]]+1 < _min[i]){
                _min[i] = _min[i-v[j]]+1;
            }
        }
    }
    cout << v[s] << endl;
    return 0;
}
