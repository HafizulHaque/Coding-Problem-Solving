// accepted

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define N 1000000
int prime[N+1];

void seive(){
    memset(prime, 1, sizeof(prime));
    prime[0] = prime[1] = 0;
    for(int i = 2; i*i <= N; ++i){
        if(prime[i]){
            for(int j = 2*i; j <= N; j += i) prime[j] = 0;
        }
    }
}

int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    seive();
    ll n, num, sq;
    cin>>n;
    while(n--){
        cin>>num;
        sq = round(sqrt(num));
        if(sq*sq==num&&prime[sq]){
            cout << "YES" << endl;
        }
        else{
            cout << "NO" << endl;
        }
    }
    return 0;
}
