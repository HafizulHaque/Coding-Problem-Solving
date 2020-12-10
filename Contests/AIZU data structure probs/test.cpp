#include <bits/stdc++.h>
using namespace std;

int main(){
    FILE *inp = freopen("inp.txt", "r", stdin);
    int n, num;
    string str;
    cin>>n;
    while(n--){
        cin>>str;
        cout << str;
        if(str=="delete" || str=="insert"){
            cin>>num;
            cout << " " << num;
        }
        cout << endl;
    }
    return 0;
}

