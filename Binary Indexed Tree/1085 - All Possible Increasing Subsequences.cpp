#include<bits/stdc++.h>
using namespace std;

#define mx 100010
#define mod 1000000007
#define lli long long
lli ara[mx],ara1[mx],tree[mx];
map<lli,int>my;

lli query(int idx,int x)
{
    lli sum=0;
    while(idx>0){
        sum=((sum%mod)+(tree[idx])%mod)%mod;
        idx-=(idx&-idx);
    }
    return sum;
}

void update(int idx,int x,lli value)
{
    while(idx<=x){
        tree[idx]+=value;
        idx+=(idx&-idx);
    }
}

void clr()
{
    memset(ara,0,sizeof(ara));
    memset(ara1,0,sizeof(ara1));
    memset(tree,0,sizeof(tree));
    my.clear();
}

int main()
{
    int t,n,cs=0;
    cin>>t;

    while(t--){
        scanf("%d",&n);

        for(int i=1;i<=n;i++){
            scanf("%lld",&ara1[i]);
            ara[i]=ara1[i];
        }

        sort(ara1+1,ara1+n+1);
        int x=1;
        for(int i=1;i<=n;i++) if(my[ara1[i]]==0)my[ara1[i]]=x++;
        for(int i=1;i<=n;i++)ara[i]=my[ara[i]];

        lli count=0,z;

        for(int i=1;i<=n;i++){
            z=query(ara[i],x)+1;
           // cout<<ara[i]<<' '<<z<<endl;
            z=z%mod;
            count=((count%mod)+z)%mod;
            update(ara[i]+1,x,z);
        }

        printf("Case %d: %lld\n",++cs,count);
        clr();
    }
}


