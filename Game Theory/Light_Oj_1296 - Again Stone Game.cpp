#include<bits/stdc++.h>
using namespace std;

int main()
{
    int t,n,x,a,b,c;
    cin>>t;
    for(int cc=1;cc<=t;cc++){
        cin>>n;
        c=0;
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            while(true){
                if(x%2==0)break;
                x=x/2;
            }
            c^=(x/2);
        }
        if(c>0)printf("Case %d: Alice\n",cc);
        else printf("Case %d: Bob\n",cc);
    }
}
