#include<bits/stdc++.h>
using namespace std;

#define mx 200010
int ara[mx],ara1[mx],bit[mx],n;
map<int,int>my;

int query(int idx)
{
    int sum=0;
    while(idx>0){
        sum+=bit[idx];
        idx-=(idx&-idx);
    }
    return sum;
}

void update(int idx,int value)
{
    while(idx<=n){
        bit[idx]+=value;
        idx+=(idx&-idx);
    }
}
void clr()
{
    my.clear();
    memset(ara,0,sizeof(ara));
    memset(ara,0,sizeof(ara1));
    memset(bit,0,sizeof(bit));
}
int main()
{
    int t;
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;i++){
            scanf("%d",&ara1[i]);
            ara[i]=ara1[i];
        }

        sort(ara1+1,ara1+n+1);
        for(int i=1;i<=n;i++) my[ara1[i]]=i;
        for(int i=1;i<=n;i++) ara[i]=my[ara[i]];

        long long count=0;
        for(int i=n;i>=1;i--){
            count+=query(ara[i]-1);
            update(ara[i],1);
        }
        cout<<count<<endl;
        clr();
    }
}
