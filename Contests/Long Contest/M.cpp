// accepted

#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define N 1000001
int prime[N];

int setPrime(){
    memset(prime, 1, sizeof(prime));
    int minIndx = sqrt(N);
    prime[0]=prime[1] = 0;
    for(int i = 2; i <= minIndx; ++i){
        if(prime[i]){
            for(int j = i*2; j <= N; j += i){
                prime[j] = 0;
            }
        }
    }
}

ld trividity(int n){
    ll sum = 1;
    int sq = sqrt(n);
    for(int i = 2; i <= sq; ++i){
        if(!(n%i)){
            sum += i;
            if(i*i!=n) sum += n/i;
        }
    }
    return sum/(long double)n;
}

int minTrividity(int minLimit, int maxLimit){
    if(minLimit==1) return 1;
    for(int i = maxLimit; i >= minLimit; --i){
        if(prime[i]) return i;
    }
    ld _min = trividity(minLimit);
    int _index = minLimit;
    for(int i = minLimit+1; i <= maxLimit; ++i){
        ld temp = trividity(i);
        if(temp<_min){
            _min = temp;
            _index = i;
        }
    }
    return _index;
}

int main(){
    //FILE *inp =freopen("in.txt", "r", stdin);
    int a, b;
    cin>>a>>b;
    setPrime();
    int res = minTrividity(a,b);
    cout << res << endl;
    //fclose(inp);
    return 0;
}
