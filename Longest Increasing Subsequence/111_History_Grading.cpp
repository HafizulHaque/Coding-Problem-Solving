#include<bits/stdc++.h>
using namespace std;
int ara[100];
int ara1[100];
int dp[100];
int m,n,a,b,c;
#define clean(a,b) memset(a,b,sizeof(a))
int main()
{
    string s;
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>ara1[i];
    getchar();
    while(getline(cin,s)){
        cout<<s.length()<<endl;
        if(s.length()<3){
                clean(dp,-1);
                int k=1;
            for(int i=s.length()-1;i>=0;i--){
                n+=(s[i]-'0')*k;
                k*=10;
            }
            cout<<n<<endl;
            for(int i=1;i<=n;i++)
                cin>>ara1[i];
        }
        else{
           int i=1,k=1,value=0;
        for(int j=s.length()-1;j>=0;j--){
            //cout<<s[j]<<' ';
            if((s[j]==' ') and value>0){
                ara[i]=value;
                i++;
                value=0;
                k=1;
            }
            else if(s[j]>='0' && s[j]<='9'){
                value+=(s[j]-'0')*k;
                k*=10;
                if(j==0){
                    ara[i]=value;
                    i++;
                }

            }
            //cout<<value<<endl;
        }
        reverse(ara,ara+i+1);
        for(int j=1;j<i;j++)
            cout<<ara[j]<<' ';
        }
        cout<<endl;

    }
}
