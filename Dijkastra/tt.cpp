#include<bits/stdc++.h>
using namespace std;

int main()
{
    int k,mx=0,x;
    cin>>k;
    for(int i=0;i<k;i++){
        cin>>x;
        mx=max(x,mx);
    }
    cout<<max(mx-25,0)<<endl;

}
