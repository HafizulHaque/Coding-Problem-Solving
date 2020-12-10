#include<bits/stdc++.h>
using namespace std;
int ara[10010];
int value[10010];

int grundy(int x)
{
    int a,b;
    memset(value,0,sizeof(value));

    int k=(x-1)/2;
    for(int j=1;j<=k;j++){
        a=j;b=x-a;
        value[ara[a]^ara[b]]=1;
    }

    for(int i=0;i<=10005;i++){
        if(value[i]==0){
            ara[x]=i;
            break;
        }
    }
}

int main()
{
    ara[1]=ara[2]=0;

    for(int i=3;i<=10005;i++){
        grundy(i);
        //cout<<i<<' '<<ara[i]<<endl;
    }

    int t,n,x;
    cin>>t;

    for(int cc=1;cc<=t;cc++){
        cin>>n;

        int k=0;
        for(int i=0;i<n;i++){
            scanf("%d",&x);
            k^=ara[x];
        }
       // cout<<k<<endl;
        if(k>0)printf("Case %d: Alice\n",cc);
        else printf("Case %d: Bob\n",cc);
    }
}

