#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *inp = freopen("inp.txt", "r", stdin);
    int n, x, y;
    cin>>n;
    int first = 0, second = 0;
    for(int i = 0; i < n ; ++i){
        cin>>x>>y;
        if(x<0) first++;
        else if(x>0) second++;
    }
    int min = first>second?second:first;
    if(min>1) cout << "No" << endl;
    else cout << "Yes" << endl;
    //fclose(inp);
    return 0;
}
