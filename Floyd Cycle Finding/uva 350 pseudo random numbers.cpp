#include<bits/stdc++.h>
using namespace std;

#define lli long long

int main()
{
    lli Z,I,M,L;
    int cas=0;

    while(cin>>Z>>I>>M>>L){
        if(Z==0 and I==0 and M==0 and L==0)break;
        lli hare=L,tortoise=L;

        do{
            hare=((hare*Z)%M+(I%M))%M;
            hare=((hare*Z)%M+(I%M))%M;
            tortoise=((tortoise*Z)%M+(I%M))%M;
        }while(hare!=tortoise);

        lli tortoise1=L;

        do{
           tortoise=((tortoise*Z)%M+(I%M))%M;
           tortoise1=((tortoise1*Z)%M+(I%M))%M;
        }while(tortoise1!=tortoise);

        lli k=0;

        do{
            k++;
            tortoise=((tortoise*Z)%M+(I%M))%M;
        }while(tortoise1!=tortoise);

        printf("Case %d: %lld\n",++cas,k);
    }
}
