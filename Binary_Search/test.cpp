#include<bits/stdc++.h>
using namespace std;

int ara[100010],n;

int main()
{
    int t,cas=0,a,b,x=0,y=0,z,q;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;

        for(int i=0;i<n;i++)scanf("%d",&ara[i]);
        printf("Case %d:\n",++cas);

        while(q--)
        {
            scanf("%d%d",&a,&b);
            x=upper_bound(ara,ara+n,b)-lower_bound(ara,ara+n,a);
            printf("%d\n",x);
        }
    }
}
