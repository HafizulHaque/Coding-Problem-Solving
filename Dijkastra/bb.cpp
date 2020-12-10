#include<bits/stdc++.h>
using namespace std;

int main()
{
    double n;
    cin>>n;
    int m=sqrt(n)+1;

    long long mx=100000000000000;
    for(int i=1;i<=m;i++){
        int x=ceil(n/double(i));
        long long ss=(x+i)*2;
        mx=min(mx,ss);
    }
    cout<<mx<<endl;
}
