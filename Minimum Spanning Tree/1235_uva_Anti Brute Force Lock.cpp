#include<bits/stdc++.h>
using namespace std;
vector<string>s,s1;
int vis[510];
int ma=0;
int check(int n)
{
    string src;
    int j=-1,min=25;

    for(int k=0;k<s1.size();k++){
            src=s1[k];
        for(int i=0;i<n;i++){
                if(vis[i]==0){
                    string a=s[i];
                    int x=0;
                    for(int j=0;j<4;j++){
                        int y=abs((src[j]-'0')-(a[j]-'0'));
                        if(y>5)y=10-y;
                        //cout<<"Y "<<y<<endl;
                        x+=y;
                    }
                    if(x<min){
                        min=x;
                        j=i;
                    }
                }
            }
    }
    //cout<<"c "<<j<<' '<<min<<endl;
    if(j>-1)ma+=min;
    return j;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        string a;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>a;
            s.push_back(a);
        }
        memset(vis,0,sizeof(vis));

        string src="0000",sr;
        int j,min=25;

        for(int i=0;i<n;i++){
            if(vis[i]==0){
                string a=s[i];
                int x=0;
                for(int j=0;j<4;j++){
                   int y=abs((src[j]-'0')-(a[j]-'0'));
                        if(y>5)y=10-y;
                       // cout<<"Y "<<y<<endl;
                        x+=y;
                }
                if(x<min){
                    min=x;
                    j=i;
                }
            }
        }
        ma+=min;
        vis[j]=1;
        //cout<<j<<' '<<s[j]<<endl;
        s1.push_back(s[j]);
        while(1){
            j=check(n);
            if(j==-1)break;
            vis[j]=1;
           // cout<<s[j]<<' '<<ma<<endl;
            s1.push_back(s[j]);
        }
        cout<<ma<<endl;
        ma=0;
        s.clear();s1.clear();
    }
}
