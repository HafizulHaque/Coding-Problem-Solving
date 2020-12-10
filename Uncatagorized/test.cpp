#include<bits/stdc++.h>
using namespace std;

int main(){
    unsigned char ch = 181;

    int x = 98974;
    x = ~(x&0);

    int a = 5, b = 2;
    int n = a-b+1;

    x<<=n;
    for(int i = 0; i < 2; ++i)
        x = (x<<1)|1;

    ch = (ch&x);

    printf("%d\n", ch);
    return 0;           // worked fine
}
