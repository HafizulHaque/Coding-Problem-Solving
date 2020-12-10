#include<bits/stdc++.h>
using namespace std;
int ara[10010],n,q,a;

int binary_S(int l,int h,int k)
{
    int index=-1,mid;

    while(l<=h){
        mid=(l+h)/2;
        if(ara[mid]==k){
            index=mid;
            h=mid-1;
        }
        else if(ara[mid]>k)h=mid-1;
        else l=mid+1;
    }
    return index;
}

int main()
{
    int cas=0;
    while(cin>>n>>q){
        if(n==0 and q==0)break;

        for(int i=0;i<n;i++)scanf("%d",&ara[i]);
        printf("CASE# %d:\n",++cas);
        sort(ara,ara+n);

        while(q--){
            cin>>a;
            int x=binary_S(0,n-1,a);
            if(x==-1)printf("%d not found\n",a);
            else printf("%d found at %d\n",a,x+1);
        }
    }
}
