#include<bits/stdc++.h>
using namespace std;

#define lli long long

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    lli a,b,c;
    cin>>a>>b>>c;

    lli hare=1,tortoise=1,cn=0;

    /// check there are any loop in sequence
    do{
        hare=((a*hare)%c+(hare%b)%c)%c;
        hare=((a*hare)%c+(hare%b)%c)%c;
        tortoise=((a*tortoise)%c+(tortoise%b)%c)%c;
        cn++;
        if(cn>20000000){
            cout<<-1<<endl;
            return 0;
        }
    }while(hare!=tortoise);

    lli tortoise1=1,m=0,k=0;

    while(tortoise1!=tortoise){
        m++;
        tortoise=((a*tortoise)%c+(tortoise%b)%c)%c;
        tortoise1=((a*tortoise1)%c+(tortoise1%b)%c)%c;
    }

    do{
        k++;
        tortoise1=((a*tortoise1)%c+(tortoise1%b)%c)%c;
    }while(tortoise1!=tortoise);

    cout<<m+k<<endl;
}
