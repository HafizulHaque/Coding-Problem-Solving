#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin>>t;
    vector<int> s;
    while(t--){
        int n, c, x;
        s.clear();
        cin>>n>>c;
        for(int i = 0; i < n ;++i){
            cin>>x;
            s.push_back(x);
        }
        sort(s.begin(), s.end());
        vector<int> vec;
        for(int i = 0; i < s.size()-2; ++i)
            vec.push_back(s[i+1]-s[i]);
        sort(vec.begin(), vec.end());
        cout << vec[vec.size()-c] << endl;
    }
    return 0;
}
