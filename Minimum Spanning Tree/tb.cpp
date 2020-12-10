#include<bits/stdc++.h>
using namespace std;

int main()
{
    int x,y,sum;
    while(cin>>x>>y){
        if(y<x)y+=30;
        int sum=y-x;
        if(sum==0)cout<<"New Moon"<<endl;
        else if(sum==14)cout<<"Full Moon"<<endl;
        else if(sum==7)cout<<"Waning Moon"<<endl;
        else if(sum>7)cout<<"Gibbous Moon"<<endl;
        else cout<<"Waxing Moon"<<endl;
    }
}


