#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin>>t;
    for(int i=1;i<=t;i++){
        double n,m,k,p,s;
        cin>>n>>m>>k>>p;
        s=n*k*p;
        printf("Case %d: %.09lf\n",i,s);
    }
}
