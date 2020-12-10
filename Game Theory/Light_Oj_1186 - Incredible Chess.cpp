#include<bits/stdc++.h>
using namespace std;
int white[110],black[110];

int main()
{
    int t,n,cc;
    cin>>t;

    for(int cc=1;cc<=t;cc++){
        cin>>n;
        for(int i=0;i<n;i++)cin>>white[i];
        for(int i=0;i<n;i++)cin>>black[i];

        int k=0;
        for(int i=0;i<n;i++)k^=(black[i]-white[i]-1);

        if(k==0)printf("Case %d: black wins\n",cc);
        else printf("Case %d: white wins\n",cc);
    }
}
