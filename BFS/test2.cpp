#include<bits/stdc++.h>
using namespace std;
int ara[]={6,2,5,5,4,5,6,3,7,6};
long long a,b;

int main()
{
    long long count=0;
    while(cin>>a>>b){
        count=0;

        for(int i=a;i<=b;i++){
            int j=i;
            while(j>0){
                int m=j%10;
                count+=ara[m];
                ///cout<<count<<endl;
                j=j/10;
            }
        }
        cout<<count<<endl;
    }
}
