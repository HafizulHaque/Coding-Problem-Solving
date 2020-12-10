// accepted
#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    long double n, m;
    long double res = 0;
    cin>>m>>n;
    for(int i = 1; i <= m; ++i){
        res += i*(pow(i/m,n)-pow((i-1)/m,n));
    }
    cout <<  res << endl;
    //fclose(inp);
    return 0;
}
