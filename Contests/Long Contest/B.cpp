// accepted n

#include <bits/stdc++.h>
using namespace std;
#define pbi pair<bool,int>
bool n_lucky(__int64 num){
    int dig = 0;
    while(num != 0){
        if(num%10==4||num%10==7){
            dig++;
        }
        num /= 10;
    }
    return (dig%10==7||dig%10==4);
}

int main(){
    //FILE *inp = freopen("in.txt", "r", stdin);
    __int64 num;
    cin>>num;
    if(n_lucky(num)) cout << "YES" << endl;
    else cout << "NO" << endl;
    //fclose(inp);
    return 0;
}
