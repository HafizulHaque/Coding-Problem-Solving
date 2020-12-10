#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,x,p,q;
    cin>>t;
    for(int cc=1;cc<=t;cc++){
        scanf("%d",&n);
        int count=0,sum=0;

        for(int i=0;i<n;i++){
            scanf("%d",&x);
            sum+=abs(x);
            if(x>0)count++;
        }
        x=__gcd(count,sum);
        if(count==0){
            printf("Case %d: inf\n",cc);
            continue;
        }
        p=sum/x;
        q=count/x;
        printf("Case %d: %d/%d\n",cc,p,q);

    }
}
