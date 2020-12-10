// accepted

#include <bits/stdc++.h>
using namespace std;

int main(){
    FILE *inp = freopen("input.txt", "r", stdin);
    long long n, _max = -10000000000, _min = 10000000000, _maxCnt = 0 , _minCnt = 0, flower;
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>flower;
        if(flower>_max){
            _max = flower;
            _maxCnt = 1;
        }
        else if(flower==_max) _maxCnt++;
        if(flower<_min){
            _min = flower;
            _minCnt = 1;
        }
        else if(flower==_min) _minCnt++;
    }
    cout << _max-_min << " ";
    if(_maxCnt==n) cout << (n*(n-1))/2 << endl;
    else cout << _maxCnt*_minCnt << endl;
    //fclose(inp);
    return 0;
}
