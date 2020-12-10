#include<bits/stdc++.h>
using namespace std;
int l,r;
string s;
map<string,bool>my;

int optimal(int i,string a,int c)
{
   // cout<<i<<' '<<s[i]<<' '<<c<<endl;
    if(c==r){
        if(my[a]==0)cout<<a<<endl;
        my[a]=1;
        return 0;
    }

    for(int j=i+1;j<l;j++){
        optimal(j,a+s[j],c+1);
        while(s[j]==s[j+1])j++;
    }
    return 0;
}
int main()
{
    while(cin>>s>>r){
        l=s.length();
        sort(s.begin(),s.end());

        for(int i=0;i<l;i++){
            string a;
            optimal(i,a+s[i],1);
        }
        s.clear();my.clear();
        //cout<<coun<<endl;
    }
}
