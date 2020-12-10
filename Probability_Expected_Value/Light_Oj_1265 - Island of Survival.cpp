#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n;
    cin>>t;
    for(int c=1;c<=t;c++){
        double d,sum=0,a;

        cin>>n>>d;
        if(n%2==1)sum=0;
        else if(n==1)sum=1;
        else{
            sum=1;
            while(n>0){
                a=(n*(n+1))/2;
                sum*=double(a-n)/double(a);
                n-=2;
            }
        }
        printf("Case %d: %.09lf\n",c,sum);
    }
}
