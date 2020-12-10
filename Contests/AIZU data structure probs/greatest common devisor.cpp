// accepted

#include <bits/stdc++.h>
using namespace std;

long gcd(long a, long b){
    if(b != 0)
        return gcd(b, a%b);
    else
        return a;
}

int main(){
    long a, b;
    cin>>a>>b;
    cout << gcd(a, b) << endl;
    return 0;
}
