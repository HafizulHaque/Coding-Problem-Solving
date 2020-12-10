#include<bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    while(cin>>s){
        int l1=0,l2=0;

        for(int i=0;i<s.length();i++){
            if(s[i]=='(')l1++;
            else l2++;
        }
        if(l1!=l2)cout<<-1<<endl;

    }
}
