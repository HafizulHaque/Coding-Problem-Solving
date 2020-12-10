#include<bits/stdc++.h>
using namespace std;s
int ara[210];

int main()
{
    int t,n,cc;
    cin>>t;

    for(int cc=1;cc<=t;cc++){
        cin>>n;
        for(int i=0;i<2*n;i++)cin>>ara[i];
        int k=0;
        for(int i=0;i<2*n;i+=2)k^=(ara[i+1]-ara[i]-1);

        if(k>0)printf("Case %d: Alice\n",cc);
        else printf("Case %d: Bob\n",cc);
    }
}

