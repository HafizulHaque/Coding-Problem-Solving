#include<bits/stdc++.h>
using namespace std;
int ara[110],n;
int vis[110];
int main()
{
    int a,b,c;

    while(cin>>n){
        long long count=0;
        for(int i=1;i<=n;i++){
            cin>>ara[i];
            if(ara[i]==1)count++;
        }

        memset(vis,0,sizeof(vis));

        if(count==1)cout<<count<<endl;
        else{
            count=1;
            long long  c=0,flag=0;
            for(int i=1;i<=n;i++){
                    c=0;
                if(ara[i]==1)
                {
                    flag=1;
                    c=0;
                    for(int j=i+1;;j++){
                        if(ara[j]==0)c++;
                        if(j>n){
                            c=0;
                            break;
                        }
                        if(ara[j]==1){
                                if(c>0)vis[j]=1;
                                break;
                        }
                    }
                    //cout<<c<<endl;
                }
                if(c>0){
                    count*=(c+1);
                }
            }
            if(flag==1)
            cout<<count<<endl;
            else cout<<0<<endl;
        }
    }
}
