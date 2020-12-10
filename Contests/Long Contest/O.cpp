// accepted

#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *inp = freopen("in.txt", "r", stdin);
    long long x,y;
    cin>>x>>y;
    if(x<=0||y<=0) cout << x << " " << y << endl;
    else{
        if((x+y)&1) cout << y << " " << x << endl;
        else cout << x << " " << y << endl;
    }
    //fclose(inp);
    return 0;
}
