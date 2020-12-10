#include<bits/stdc++.h>
using namespace std;

long long ara[30],ara1[30];
long long l=100000000000000000,n,m,sum;
int save()
{
    int j=1;
    ara[1]=10;
    ara1[1]=9;
    j++;
    while(1){
        ara[j]=ara[j-1]*10;
        if(ara[j]>l)break;
        ara1[j]=ara1[j-1]*9;
        cout<<ara[j]<<' '<<ara1[j]<<endl;
        j++;
    }
    for(int i=1;i<j;i++){
        cout<<ara1[i]<<endl;
    }
    return j;
}
int main()
{
    int l=save();
    while(cin>>n){
        while(n>10){

        }
    }
}
