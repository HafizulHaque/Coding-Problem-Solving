#include <bits/stdc++.h>
using namespace std;
#define LO 0
#define HI 1
#define EPS 1e-7
double p, q, r, s, t, u, x;

double f(double x){
    return p*exp(-x)+q*sin(x)+r*cos(x)+s*tan(x)+t*x*x+u;
}

double find_x(){
    double lo = LO, hi = HI;
    while(lo+EPS<hi){
        x = (lo+hi)/2;
        if(f(lo)*f(x)>0) lo = x;
        else hi = x;
    }
    return x;
}

int main(){
    FILE *inp = freopen("input.txt", "r", stdin);
    while(cin>>p>>q>>r>>s>>t){
        if(f(0)*f(1)>0){
            cout << "No solution" << endl;
        }
        else{
            printf("%lf\n", find_x());
        }
    }
    return 0;
}
