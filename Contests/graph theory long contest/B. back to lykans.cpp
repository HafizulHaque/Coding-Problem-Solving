#include <bits/stdc++.h>
using namespace std;
#define ITR map<int, int>::iterator
int main(){
    //FILE *inp = freopen("inputt.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    for(int i = 0; i < t; ++i){
        int n, a, b;
        map<int, int> record;
        ITR itr;
        pair<ITR, bool> det;
        scanf("%d", &n);
        while(n--){
            scanf("%d%d", &a, &b);
            det = record.insert(make_pair(a,1));
            if(det.second==false)
                det.first->second++;
            det = record.insert(make_pair(b,1));
            if(det.second==false)
                det.first->second++;
        }
        int max = 0;
        for(itr = record.begin(); itr != record.end(); ++itr){
            if(itr->second>max) max = itr->second;
        }
        printf("Case %d: %d\n", i+1, max);
    }
    //fclose(inp);
    return 0;
}
