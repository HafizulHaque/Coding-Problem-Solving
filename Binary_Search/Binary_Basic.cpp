#include<bits/stdc++.h>
using namespace std;
int ara[100010];
int n;

int binary(int low,int high,int key)
{
    int mid,index=-1;
    while(low<=high){
        mid=(low+high)/2;
    cout<<low<<' '<<high<<' '<<mid<<endl;
        if(ara[mid]==key){
            index=mid;
            break;
        }
        else if(ara[mid]>key)high=mid-1;
        else low=mid+1;
    }
    cout<<index<<endl;

    return index;
}

int main()
{
    while(cin>>n){
        for(int i=0;i<n;i++)cin>>ara[i];

        sort(ara,ara+n);
        int value;
        cin>>value;
        int l=0,h=n;

        int index=binary(l,h,value);
        if(index!=-1)cout<<ara[index]<<endl;
        else cout<<"Not Found"<<endl;
    }
}
