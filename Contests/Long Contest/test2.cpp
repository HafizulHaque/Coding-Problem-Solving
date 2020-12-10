#include <bits/stdc++.h>
using namespace std;
#define N 4005
string str;
int det[N][N];
vector<string>result;

int main(){
    FILE *inp = freopen("in.txt", "r", stdin);
    int n, sz;
    cin>>str;
    n = str.length();
    cout << str << endl;
    cout << "---------------------------" << endl;
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            det[i][j] = 0;
        }
    }
    for(int i = 0; i < n; ++i){
        int l = i, r = i, l1 = i, r1 = i+1;
        while(l>=0&&r<n){
            if(str[l]==str[r]){
                det[l--][r++] = 1;
            }
            else break;
        }
        while(l1>=0&&r1<n){
            if(str[l1]==str[r1]){
                det[l1--][r1++] = 1;
            }
            else break;
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            cout << det[i][j] << "  ";
        }
        cout << endl;
    }
    cout << "---------------------------" << endl;
    int a = 0;
    while(a<n){
        for(int b = n-1; b >= a; --b){
            if(det[a][b]){
                result.push_back(str.substr(a,b-a+1));
                a = b+1;
                break;
            }
        }
    }
    sz = result.size();
    cout << sz << endl;
    for(int i = 0; i < sz; ++i){
        if(i) cout << " ";
        cout << result[i];
    }
    cout << endl;
    fclose(inp);
    return 0;
}
