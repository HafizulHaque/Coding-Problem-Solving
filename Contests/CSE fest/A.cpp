#include <bits/stdc++.h>
using namespace std;

int main(){
    FILE *inp_file = freopen("inp.txt", "r", stdin);
    int p, n;
    char str[44];
    int seq[44];
    int count[8];
    cin>>p;
    while(p--){
        cin>>n;
        cout << n;
        cin>> str;

        for(int i = 0; i < 40; ++i){
            if(str[i]=='T') seq[i] = 0;
            else if(str[i]=='H') seq[i] = 1;
        }
        for(int i = 0; i < 8; ++i)
            count[i] = 0;
        for(int i = 0; i <= 40-3; ++i)
            count[seq[i]*4+seq[i+1]*2+seq[i+2]]++;
        for(int i = 0; i < 8; ++i)
            cout << " " << count[i];
        cout << endl;
    }
    fclose(inp_file);
    return 0;
}
