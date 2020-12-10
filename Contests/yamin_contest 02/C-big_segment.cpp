// accepted

#include <bits/stdc++.h>
using namespace std;
typedef struct Segment{
    long l, r;
    int index;
    bool operator <(const Segment &x) const{
        return l<x.l||(l==x.l&&r>x.r);
    }
};

Segment consSeg(int a, int b, int indx){
    Segment x;
    x.l = a;
    x.r = b;
    x.index = indx;
    return x;
}

int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    long a, b, n;
    vector<Segment>segs;
    cin>>n;
    for(int i = 1; i <= n; ++i){
        cin>>a>>b;
        segs.push_back(consSeg(a,b,i));
    }
    sort(segs.begin(), segs.end());
    for(int i = 1; i < n ; ++i){
        if(segs[i].r>segs[0].r){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << segs[0].index << endl;
    //fclose(inp);
    return 0;
}
