// accepted

#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *inp = freopen("in.txt", "r", stdin);
    int n, key, med, _min  = 0, _max = 0, place, index, cnt = 0;
    cin>>n>>key;
    place = n+1;
    int arr[n+2];
    for(int i = 1; i <= n; ++i) cin>>arr[i];
    sort(arr+1, arr+(n+1));
    for(int i = 1; i <= n; ++i){
        if(arr[i]==key){
            if(_min==0) _min = i;
            _max = i;
        }
        if(arr[i]>key&&place>i) place = i;
    }
    if(!_min){
        n++;
        index = place;
        med = (n+1)/2;
        cnt++;
    }
    else{
        med = (n+1)/2;
        if(arr[med]==key) index = med;
        else if(arr[med]<key) index = _min;
        else if(arr[med]>key) index = _max;
    }
    while(index!=med){
        cnt++;
        n++;
        if(index<med) index++;
        med = (n+1)/2;
    }
    cout << cnt << endl;
    //fclose(inp);
    return 0;
}
