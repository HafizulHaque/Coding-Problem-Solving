#include<bits/stdc++.h>
using namespace std;
string txt,pat,ztxt;

int z[10000000];
void zzz()
{
    int l=0,r=0,k,x=ztxt.size();
    for(int i=1;i<x;i++){
        if(i>r){
            l=r=i;
            while(r<x and ztxt[r]==ztxt[r-l])
                r++;
            z[i]=r-l;r--;
        }
        else{
            k=i-l;
            if(z[k]<r-i+1)z[i]=z[k];
            else{
                l=i;
                while(r<x and ztxt[r]==ztxt[r-l])
                    r++;
                z[i]=r-l;r--;
            }
        }
    }
}
int main()
{
    int t,cs=0;
    cin>>t;

    while(t--){
        cin>>txt>>pat;
        ztxt+=pat;ztxt+='$';ztxt+=txt;
        zzz();
        int a=pat.size(),b=ztxt.size(),count=0;
        for(int i=a+1;i<b;i++){
            //cout<<z[i]<<' '<<i-pat.size()-1<<endl;
            if(z[i]==a) count++;
        }
        printf("Case %d: %d\n",++cs,count);
        ztxt.clear();
    }
}
