// accepted

#include <bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    int n;
    ll diff, cnt = 0;
    cin>>n>>diff;
    long dot[n+1];
    dot[0] = 0;
    for(int i = 1; i <= n; ++i){
        scanf("%ld", &dot[i]);
    }
    int l = 1, r = 3;
    ll t;
    while(r<=n){
        if(dot[r]-dot[l]<=diff&&r-l>=2){
            t = r-l;
            cnt += (t*(t-1))/2;
            r++;
        }
        else if(dot[r]-dot[l]<diff) r++;
        else l++;
        if(l==n) break;
    }
    cout << cnt << endl;
    return 0;
}
