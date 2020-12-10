#include<bits/stdc++.h>
using namespace std;

int main()
{
    long long t,r,c,x;
    scanf("%lld",&t);

    for(int cc=1;cc<=t;cc++){
        scanf("%lld %lld",&r,&c);
        long long k=0;

        if((r%2==0 and c%2==0) or (r%2==1 and c%2==1)){
            for(int i=1;i<=r;i++){
                for(int j=1;j<=c;j++){
                    scanf("%lld",&x);
                    if(i%2==1 and j%2==0)k^=x;
                    else if(i%2==0 and j%2==1)k^=x;
                }
            }
        }
        else{
           for(int i=1;i<=r;i++){
                for(int j=1;j<=c;j++){
                    scanf("%lld",&x);
                    if(i%2==1 and j%2==1)k^=x;
                    else if(i%2==0 and j%2==0)k^=x;
                }
            }
        }

        if(k>0)printf("Case %d: win\n",cc);
        else printf("Case %d: lose\n",cc);
    }

}
