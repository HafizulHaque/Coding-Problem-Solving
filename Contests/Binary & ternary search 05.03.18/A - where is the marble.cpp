// accepted

#include <bits/stdc++.h>
using namespace std;
int arr[10002];

int b_search(int key, int beg, int lst){
    int mid, ret = -1;
    while(beg<=lst){
        mid = beg+(lst-beg)/2;
        if(arr[mid]==key){
            ret = mid;
            break;
        }
        else if(key>arr[mid]) beg = mid+1;
        else lst = mid-1;
    }
    if(ret==-1);
    else{
        while(arr[ret-1]==key) ret--;
    }
    return ret;
}

int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    //FILE *out = freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    int caseNo = 0, ans;
    int n, q, key;
    while(cin>>n>>q){
        if(n==0&&q==0) break;
        cout << "CASE# " << ++caseNo << ":" << endl;
        for(int i = 0; i < n; ++i) cin>>arr[i];
        sort(arr, arr+n);
        while(q--){
            cin>>key;
            ans = b_search(key, 0, n-1);
            if(ans==-1) cout << key << " not found" << endl;
            else cout << key << " found at " << ans+1 << endl;
        }
    }
    //fclose(inp);
    //fclose(out);
    return 0;
}
