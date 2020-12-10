#include<bits/stdc++.h>
using namespace std;
long long x1,x2,y1,y2,s1,s2;
int main()
{
    while(cin>>x1>>y1>>x2>>y2){
        s1=abs(x1-x2);
        s2=abs(y1-y2);
        cout<<max(s1,s2)<<endl;
    }
}
