#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *file = freopen("C.txt", "r", stdin);
    int g;
    cin>>g;
    while(g--){
        int n, m;
        long long sum = 0, x, ans;
        cin>>n>>m>>x;
        int a[n];
        int b[m];
        for(int i = 0; i < n; ++i){
            cin>>a[i];
        }
        for(int i = 0; i < m; ++i){
            cin>>b[i];
        }

        int p = 0, q = 0;
        while(sum <= x && p < n){
            sum += a[p++];
        }
        ans = p;
        while(q<m && p>=0){
            sum += b[q++];

            while(sum>x && p>0){
                sum -= a[--p];
            }

            if(sum <= x && ans < p+q) ans = p+q;
        }
        cout << ans << endl;
    }
    //fclose(file);
    return 0;
}
