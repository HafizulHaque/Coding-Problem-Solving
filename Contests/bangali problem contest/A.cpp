// accepted

#include <bits/stdc++.h>
using namespace std;
#define VAL 1000000007
#define i64 long long
i64 F(i64 N,i64 P)
{
	if(P==0) return 1;
	if(P%2==0){
		i64 ret=F(N,P/2);
		return ((ret%VAL)*(ret%VAL))%VAL;
	}
	else return ((N%VAL)*(F(N,P-1)%VAL))%VAL;

}

int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    i64 n, m;
    int t;
    cin>>t;
    while(t--){
        cin>>n>>m;
        cout << F(n,m) << endl;
    }
    return 0;
}
