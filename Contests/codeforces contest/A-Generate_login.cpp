// accepted
#include <bits/stdc++.h>
using namespace std;

int main(){
    FILE *inp = freopen("input.txt", "r", stdin);
    string first, last;
    cin>>first>>last;
    int len = first.length();
    cout << first[0];
    for(int i = 1; i<len&&first[i]<last[0]; ++i){
        cout << first[i];
    }
    cout << last[0] << endl;
    return 0;
}
