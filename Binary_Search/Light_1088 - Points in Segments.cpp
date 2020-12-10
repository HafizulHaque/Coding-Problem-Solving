#include<bits/stdc++.h>
using namespace std;

int ara[100010],n;
int binary_low(int l,int h,int k)
{
    int index=-1,mid;
    while(l<=h){
        mid=(l+h)/2;
        if(ara[mid]>=k)h=mid-1;
        else{
            index=mid;
            l=mid+1;
        }
    }
    //cout<<index<<endl;
    if(index==-1)index=-1;
    return index;
}

int binary_high(int l,int h,int k)
{
    int index=-1,mid;
    while(l<=h){
        mid=(l+h)/2;
        if(ara[mid]<=k)l=mid+1;
        else{
            index=mid;
            h=mid-1;
        }
    }
  //  cout<<index<<endl;
    if(index==-1)index=n;
    return index;
}

int main()
{
    int t,cas=0,a,b,x,y,z,q;
    cin>>t;
    while(t--)
    {
        cin>>n>>q;

        for(int i=0;i<n;i++)scanf("%d",&ara[i]);
        sort(ara,ara+n);
        printf("Case %d:\n",++cas);

        while(q--)
        {
            scanf("%d%d",&a,&b);
            x=binary_low(0,n-1,a);
            y=binary_high(0,n-1,b);

          //  cout<<x<<' '<<y<<endl;
           // cout<<abs(y-x)<<endl;
            printf("%d\n",abs(y-x)-1);
        }
    }
}
