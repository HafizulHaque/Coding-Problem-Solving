#include<bits/stdc++.h>
using namespace std;

int play(int n)
{
    if(n==0 or n==1)return 0;
   // cout<<n<<' '<<play((n-2))<<' '<<play((n-3))<<' '<<play((n-5))<<endl;
    if(n>=2 and play(n-2)==0)return 1;
    if(n>=3 and play(n-3)==0)return 1;
    if(n>=5 and play(n-5)==0)return 1;
    return 0;
}
int main()
{
    int n;
    while(cin>>n){
        for(int i=1;i<=20;i++)
            cout<<i<<' '<<play(i)<<endl;
    }
}
