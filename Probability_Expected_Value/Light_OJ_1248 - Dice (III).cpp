#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    cin>>t;

    for(int c=1;c<=t;c++){
        cin>>n;
        double sum=0;
        for(int i=1;i<=n;i++){
            sum+=double(n)/double(i);
        }
        printf("Case %d: %.09lf\n",c,sum);
    }

}

