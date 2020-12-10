// accepted

#include <bits/stdc++.h>
using namespace std;

int rev(unsigned char ch){
    int res = 0;
    for(int i = 0; i < 8; ++i){
        if(ch&(1<<i)) res += pow(2,7-i);
    }
    return res;
}

int trans(int index, unsigned char prev, unsigned char current){
    int val, res;
    if(index==0) val = 0;
    else val = rev(prev);
    res = rev(current);
    return ((val-res)+256)%256;
}

int main(){
    //FILE *inp = freopen("in.txt", "r", stdin);
    char str[200];
    unsigned char ch1, ch2;
    gets(str);
    int len = strlen(str);
    for(int i = 0; i < len; ++i){
        if(i) ch1 = str[i-1];
        ch2 = str[i];
        cout << trans(i, ch1, ch2) << endl;
    }
    //fclose(inp);
    return 0;
}
