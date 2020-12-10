#include <bits/stdc++.h>
using namespace std;
typedef struct Item{
    int l;
    int r;
    int dur;
    int cost;
};

int main(){
    FILE *inp = freopen("inp.txt", "r", stdin);
    int n, vacation;
    cin>>n;
    Item items[n];
    for(int i = 0; i < n; ++i){
        cin>>items[i].l>>items[i].r>>items[i].cost;
        items[i].dur = items[i].r-items[i].l+1;
    }
    //vector<pii> vec;
    int _min = 100000000;
    for(int i = 0; i < n; ++i){
        for(int j = i+1; j < n; ++j){
            if(items[i].dur+items[j].dur==vacation){
                    // vec.push_back(make_pair(i,j));
                    if(items[i].r<items[j].l||items[j].r<items[j].l){
                        _min = min(_min,items[i].cost+items[j].cost);
                    }
            }
        }
    }
    cout << _min << endl;
    fclose(inp);
    return 0;
}
