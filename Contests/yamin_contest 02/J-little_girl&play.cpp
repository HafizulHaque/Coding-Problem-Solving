// accepted
#include <bits/stdc++.h>
using namespace std;

int main(){
    FILE *inp = freopen("input.txt", "r", stdin);
    char str[1001];
    int alp[26];
    int len, oddCnt = 0;
    scanf("%s", str);
    len = strlen(str);
    memset(alp, 0, sizeof(alp));
    for(int i = 0; i < len; ++i){
        alp[str[i]-'a']++;
    }
    for(int i = 0; i < 26; ++i){
        if(alp[i]&1) oddCnt++;
    }
    if(!oddCnt||oddCnt&1) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}
