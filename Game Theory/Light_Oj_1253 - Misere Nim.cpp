#include<bits/stdc++.h>
using namespace std;

#define lli long long
lli ara[110];

int main()
{
    int t,cc,k;
    cin>>t;
    for(int cc=1;cc<=t;cc++){
        lli a,b=0,c=0;
        scanf("%d",&k);
        for(int i=0;i<k;i++){
            scanf("%lld",&ara[i]);
            if(ara[i]!=1)c=1;
            b^=ara[i];
        }
        if(k%2==1 and c==0)a=2;
        else if(k%2==0 and c==0)a=1;
        else{
            if(b==0)a=2;
            else a=1;
        }
        if(a==1)printf("Case %d: Alice\n",cc);
        else printf("Case %d: Bob\n",cc);
    }
}
