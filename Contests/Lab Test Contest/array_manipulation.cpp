#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, m;
    int a, b, k;
    cin>>n>>m;
    vector<pair<int, int> > vec;
    for(int i = 0; i < m; ++i){
        cin>>a>>b>>k;
        vec.push_back(make_pair(a, k));
        vec.push_back(make_pair(b+1, -k));
    }
    sort(vec.begin(), vec.end());
    int sum = 0, _max = 0;
    for(int i = 0; i < 2*m; ++i){
        sum += vec[i].second;
        _max = max(sum, _max);
    }
    cout << _max << endl;
    return 0;
}

