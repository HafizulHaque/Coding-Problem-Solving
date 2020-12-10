#include<bits/stdc++.h>
using namespace std;
long long x,sum;
int main()
{
    while(cin>>x){
        sum=0;
        sum+=(x/5);x=x%5;
        sum+=(x/4);x=x%4;
        sum+=(x/3);x=x%3;
        sum+=(x/2);x=x%2;
        sum+=(x/1);x=x%1;
        cout<<sum<<endl;
    }

}

