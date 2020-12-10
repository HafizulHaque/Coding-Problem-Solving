// accepted

#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    long n, num[3], div[3], _max = 0, ans, temp;
    cin>>n>>num[0]>>num[1]>>num[2];
    sort(num, num+3, greater<long>());
    for(int i = 0; i < 3; ++i) div[i] = n/num[i];
    for(int i = div[0]; i >= 0; --i){
        for(int j = div[1]; j >= 0; --j){
            int k = n-(i*num[0]+j*num[1]);
            if(k%num[2]==0){
                k /= num[2];
                if(i+j+k>_max) _max = i+j+k;
            }
        }
    }
    cout << _max << endl;
    return 0;
 }
