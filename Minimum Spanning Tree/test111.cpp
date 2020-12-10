#include<bits/stdc++.h>
using namespace std;

#define pii pair<int,int>
string s[2010],s1[310];
int n,m,x,y;
vector<pii>v;

int check(pii src)
{
    int a=src.first;
    int b=src.second;
    //cout<<a<<' '<<b<<endl;
    string my[310];
    //cout<<"m "<<a<<' '<<b<<' '<<x<<' '<<y<<endl;
    int k=1,q=1,r=0;
   for(int i=a;i<a+n;i++){
       if(i>x)break;
        string sss;
        for(int j=b;j<b+m;j++){
            if(j>=y)break;
            sss+=s[i][j];
        }
        //cout<<sss<<endl;
        my[k]=sss;
        k++;
   }

//cout<<"final"<<endl;
    int flag=0;
   for(int i=1;i<=k;i++){
       // cout<<my[i]<<' '<<s1[i]<<endl;
        if(my[i]!=s1[i]){
            flag=1;
            break;
        }
   }
   //cout<<a<<' '<<b<<endl;
   if(flag==0)v.push_back(pii(a,b+1));
}
int main()
{
    while(cin>>n>>m){
        for(int i=1;i<=n;i++)
            cin>>s1[i];
        cin>>x>>y;

        for(int i=1;i<=x;i++)
            cin>>s[i];

        char z=s1[1][0];
        //cout<<z<<endl;
        for(int i=1;i<=x;i++){
            for(int j=0;j<y;j++){
                   // cout<<s[i][j]<<endl;
                if(s[i][j]==z){
                    check(pii(i,j));
                }
            }
        }

        if(v.size()==0) printf("NO MATCH FOUND...\n");
        else{
            for(int i=0;i<v.size();i++){
            cout<<"("<<v[i].first<<','<<v[i].second<<')'<<endl;
            }
        }
        v.clear();
    }
}
