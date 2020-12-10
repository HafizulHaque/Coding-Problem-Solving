#include<bits/stdc++.h>
using namespace std;

char ara[]={'a','b','c','d'};
vector<char>result;
int taken[20];

void call()
{
    if(result.size()==4)
    {
        for(int i=0;i<4;i++){
            printf("%c",result[i]);
        }
        cout<<endl;
        return;
    }

    for(int i=0;i<4;i++){
        if(taken[i]==0)
        {
            cout<<i<<' '<<taken[i]<<' '<<' '<<ara[i];
            taken[i]=1;result.push_back(ara[i]);
            cout<<result.size()<<endl;
            call();
           // cout<<i<<' '<<ara[i]<<endl;
            taken[i]=0;result.pop_back();
        }
    }
}
int main()
{
    call();
}
