#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *inp = freopen("in.txt", "r", stdin);
    int y, n, k, r, x;
    vector<int>vec;
    cin>>y>>k>>n;
    for(int i = y/k+1; ; ++i){
        x = (k*i-y);
        if(x<=0) continue;
        if(x+y<=n) vec.push_back(x);
        else break;
    }
    if(vec.empty()){
        cout << -1 << endl;
    }
    else{
        sort(vec.begin(), vec.end());
        for(auto itr = vec.begin(); itr != vec.end(); ++itr){
            cout << *itr << " ";
        }
        cout << endl;
    }
    //fclose(inp);
    return 0;
}
