// accepted

#include <bits/stdc++.h>
using namespace std;

void printQueue(int a, int b, char x, char y){
    int n = a+b;
    for(int i = 1; i <= n; i++){
        if(i&1){
           cout << x ;
        }
        else{
             if(b==0) cout << x;
             else{
                cout << y;
                b--;
             }
        }
    }
    cout << endl;
}

int main(){
    FILE *inp = freopen("input.txt", "r", stdin);
    FILE *out = freopen("output.txt", "w", stdout);
    int n, m;
    cin>>n>>m;
    if(n>m) printQueue(n, m, 'B', 'G');
    else printQueue(m, n, 'G', 'B');
    fclose(inp);
    fclose(out);
    return 0;
}
