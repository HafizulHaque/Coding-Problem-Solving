#include<bits/stdc++.h>
using namespace std;

int main()
{
   int t;
   cin>>t;

   for(int c=1;c<=t;c++){
      long long b,d,ct=0;
      cin>>b>>d;
      if(b>d)ct=((b-(d+1))/d)+1;
      printf("Case %d: %lld\n",c,ct);
   }
}
