#include<bits/stdc++.h>
using namespace std;

int z[3000010];
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
    cin>>txt;
    pat=txt;
    ztxt+=pat;ztxt+='#';ztxt+=txt;
    int a=txt.size(),b=ztxt.size();
    zzz(b);

    int count=0;
    for(int i=a+2;i<b;i++){
        cout<<i<<' '<<ztxt[i]<<' '<<z[i]<<endl;
        if(i+z[i]==b){
            count=max(count,z[i]);
        }
    }
    cout<<count<<endl;
    if(count==0)
        cout<<"Just a legend"<<endl;
    else{
        ztxt.clear();
        for(int i=0;i<count;i++)
            ztxt+=txt[i];
        ztxt+='#';
        for(int i=1;i<a-1;i++)
            ztxt+=txt[i];
        cout<<ztxt<<endl;

    }

}


