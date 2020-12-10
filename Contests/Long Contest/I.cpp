// accepted

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int> // 1st team score, 2nd team score
#define mii map<int, pii>  // dis, team

int main(){
    //FILE *inp = freopen("in.txt", "r", stdin);
    int n, m, dis, _max, a, b;
    mii throws;
    pii result;

    //input
    scanf("%d", &n);
    for(int i = 0; i < n; ++i){
        scanf("%d", &dis);
        auto success = throws.insert(make_pair(dis,make_pair(1,0)));
        if(success.second==false){
            ((success.first)->second).first += 1;
        }
    }
    scanf("%d", &m);
    for(int i = 0; i < m; ++i){
        scanf("%d", &dis);
        auto success = throws.insert(make_pair(dis,make_pair(0,1)));
        if(success.second==false){
            ((success.first)->second).second += 1;
        }
    }

    // main algorithm
    a = 3*n;
    b = 3*m;
    _max = a-b;
    result.first = a;
    result.second = b;
    for(auto itr = throws.begin(); itr != throws.end(); ++itr){
        int distance = itr->first;
        pii throw_cnt = itr->second;
        a -= throw_cnt.first;
        b -= throw_cnt.second;
        if((a-b)>_max){
            _max = a-b;
            result.first = a;
            result.second = b;
        }
    }
    printf("%d:%d\n", result.first, result.second);
    //fclose(inp);
    return 0;
}
