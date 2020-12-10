#include<bits/stdc++.h>
using namespace std;

int main(){
    int a = 103;

    printf("bitwise left shift 2  : %d\n", a<<2);
    printf("bitwise right shift 5 : %d\n", a>>5);

    int b = 5;  // 00000101
    int c = 9;  // 00001001

    printf("bitwise OR      : %d\n", b|c);   // 00001101 = 13
    printf("bitwise AND     : %d\n", b&c);   // 00000001 = 1
    printf("bitwise XOR     : %d\n", b^c);   // 00001100 = 12
    printf("complement of b : %d\n", ~b);   //  -b-1


}
