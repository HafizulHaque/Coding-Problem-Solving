#include<bits/stdc++.h>
using namespace std;
int lps[1000010],n,x;
string txt,pat;

int find_match()
{
    int count=0,i=0,j=0;
    while(i<n){
        if(txt[i]==pat[j]){
            i++;j++;
        }
        else{
            if(j>0)j=lps[j-1];
            else i++;
        }
        if(j==x){
            count++;
            j=lps[j-1];
        }
    }
    return count;
}

void computeLPS()
{
    for(int i=1,len=0;i<x;)
    {
        if(pat[i]==pat[len])lps[i++]=++len;
        else{
            if(len>0)len=lps[len-1];
            else lps[i++]=0;
        }
    }
}
int main()
{
    int t,cs=0;
    cin>>t;
    while(t--){
        cin>>txt>>pat;
        n=txt.size(); x=pat.size();
        computeLPS();
        printf("Case %d: %d\n",++cs,find_match());
    }
}
