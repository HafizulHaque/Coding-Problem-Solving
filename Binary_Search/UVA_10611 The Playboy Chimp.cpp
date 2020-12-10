#include<bits/stdc++.h>
using namespace std;
int ara[50010],n;

int binary_S(int low,int high,int key)
{
    int index1=-1,index=-1,mid;
    int l=low,h=high;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(ara[mid]>=key)high=mid-1;
        else{
            index=mid;
            low=mid+1;
        }
    }
   // cout<<index<<endl;

    while(l<=h)
    {
        mid=(l+h)/2;
      //  cout<<l<<' '<<h<<' '<<mid<<endl;
        if(ara[mid]<=key){
            l=mid+1;
        }
        else if(ara[mid]>key){
            index1=mid;
            h=mid-1;
        }
    }

    if(index==-1)printf("X ");
    else printf("%d ",ara[index]);
    if(index1==-1)printf("X\n");
    else printf("%d\n",ara[index1]);
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)scanf("%d",&ara[i]);

    int q,l,h,k;
    cin>>q;

    while(q--){
        scanf("%d",&k);
        binary_S(0,n-1,k);
    }
}
