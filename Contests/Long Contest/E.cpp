// accepted

#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *inp = freopen("in.txt", "r", stdin);
    int n, m, l, s;
    cin>>n>>m;
    l = n>m? n:m;
    s = n<m? n:m;
    cout << l-1 << " " << s << endl;
    //fclose(inp);
    return 0;
}
