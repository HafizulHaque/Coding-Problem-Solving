#include <bits/stdc++.h>
using namespace std;
#define pill pair<int, long long>

int main(){
    int test_case, n;
    int u, v;
    long long w;
    cin>>test_case;
    while(test_case--){
        cin>>n;
        vector<pill> edge[n];
        for(int i = 1; i < n; ++i){
            cin>>u>>v>>w;
            edge[u].push_back(make_pair(v, w));
        }
    }

}
