#include <bits/stdc++.h>
using namespace std;

unsigned long long evenFibSum(unsigned long long limit){
    if(limit < 2)
        return 0;
    if(limit == 2)
        return 2;

    unsigned long long fib1 = 0;
    unsigned long long fib2 = 2;
    unsigned long long sum = fib1 + fib2;

    while(fib2 <= limit){
        unsigned long long fib3 = 4*fib2 + fib1;
        if(fib3 > limit)
            break;
        fib1 = fib2;
        fib2 = fib3;
        sum += fib2;
    }
    return sum;
}

int main() {
    int t;
    unsigned long long n;
    cin>>t;
    while(t--){
        cin>>n;
        cout << evenFibSum(n) << endl;
    }
    return 0;
}

