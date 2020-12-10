#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    //FILE *inp = freopen("inp.txt", "r", stdin);
    ios_base::sync_with_stdio(0);
    int n;
    ll cut;
    double ans;

    while(cin>>n>>cut){
        if(n==0&&cut==0) break;

        ll arr[n+1];
        ll total[n+1];
        memset(arr, 0, sizeof(arr));
        memset(total, 0, sizeof(total));

        for(int i = 1; i <= n; ++i){
            cin>>arr[i];
            total[i] = total[i-1]+arr[i];
        }
        //cout << "total: " << total[n] << "  " << "cut " << cut << "  n = " << n << endl;
        if(cut==0||total[n]==cut) cout << ":D" << endl;
        else if(total[n]>cut) cout << "-.-" << endl;
        else{
            ans = (total[n]-cut)/(double)n;
            printf("%.4lf\n", ans);
        }
    }

    //fclose(inp);
    return 0;
}
