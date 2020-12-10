#include<bits/stdc++.h>
using namespace std;

int z[3000000];
string txt,pat,ztxt;

int zzz(int x)
{
    int l=0,r=0,k;

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
        cin>>txt;
        pat=txt;
        reverse(pat.begin(),pat.end());
        ztxt+=pat;ztxt+='#';ztxt+=txt;
        int a=pat.size(),b=ztxt.size(),mx=0;
        zzz(b);

        for(int i=a;i<b;i++){
            if(i+z[i]==b){
                mx=z[i];
                break;
            }
        }
        int v=(a-mx)*2+mx;
        printf("Case %d: %d\n",++cs,v);
        ztxt.clear();pat.clear(),txt.clear();

    }

}
