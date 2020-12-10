#include<bits/stdc++.h>
using namespace std;

double prob[110],vv[10010];
int value[110];

int main()
{
    int t,n,a;
    cin>>t;
    double cap,x,y;
    for(int c=1;c<=t;c++){
        cin>>cap>>n;

        int sum=0;
        for(int i=0;i<n;i++){
            scanf("%d %lf",&value[i],&prob[i]);
            sum+=value[i];
        }

        for(int i=1;i<=sum;i++)vv[i]=1;
        vv[0]=0;

        for(int i=0;i<n;i++){
            for(int j=sum;j>=1;j--){
                a=j-value[i];
                if(a>=0)
                    vv[j]=min(vv[j],(vv[a]+(1-vv[a])*prob[i]));
            }
        }

        int ans=0;
        for(int i=0;i<=sum;i++)
            if(vv[i]<cap)
                ans=i;


        printf("Case %d: %d\n",c,ans);
    }
}
