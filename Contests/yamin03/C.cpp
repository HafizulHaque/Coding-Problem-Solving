// accepted

#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    int temph=0, tempm=0, h, m, n, maxCnt = 0, cnt = 0;
    scanf("%d", &n);
    while(n--){
        scanf("%d%d", &h, &m);
        if(h==temph&&m==tempm){
            cnt++;
        }
        else{
            maxCnt = max(maxCnt, cnt);
            temph = h;
            tempm = m;
            cnt = 1;
        }
    }
    maxCnt = max(cnt, maxCnt);
    cout << maxCnt << endl;
    return 0;
}
