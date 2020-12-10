#include<bits/stdc++.h>
using namespace std;
vector<string>v;
bool vis[]
int main()
{
    string s;
    while(getline(cin,s))
    {
        string s1;
        for(int i=0;i<s.length();i++){
            if(s[i]==' '){
                v.push_back(s1);
                s1.clear();
            }
            else if(i==s.length()-1){
                s1+=s[i];
                v.push_back(s1);
                s1.clear();
            }
            else{s1+=s[i];}
            cout<<s1<<endl;
        }

        for(int i=0;i<v.size();i++)
            cout<<v[i]<<endl;
    }
}
