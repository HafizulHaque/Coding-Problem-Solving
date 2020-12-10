#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *inp = freopen("in.txt", "r", stdin);
    int n;
    cin>>n;
    long long minUpto, maxProfit , firstRate, secondRate, rate;
    cin>>firstRate>>secondRate;
    maxProfit = secondRate-firstRate;
    minUpto = min(firstRate, secondRate);
    for(int i = 2; i < n; ++i){
        cin>>rate;
        maxProfit = max(maxProfit, rate-minUpto);
        minUpto = min(rate, minUpto);
    }
    cout << maxProfit << endl;
    //fclose(inp);
    return 0;
}
