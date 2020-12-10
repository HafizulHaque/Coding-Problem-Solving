#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>  // <size, keeping>
vector<pii>vec;
pii b_s(int low, int high, int key){
    if(vec[high].first<key) return make_pair(0,high);
    int mid;
    while(low<=high){
        mid = low+(high-low)/2;
        if(vec[mid].first==key){
            while(vec[mid].second&&mid<=high) mid++;
            if(mid>high) return make_pair(0,high);
            else return make_pair(1, mid);
        }
        else if(vec[mid].first<key) low = mid+1;
        else high = mid-1;
    }
    mid = high>low? low:high;
    while(vec[mid].second&&mid<=high) mid++;
    if(mid>high) return make_pair(0,high);
    else return make_pair(1, mid);
}

int main(){
    FILE *inp = freopen("in.txt", "r", stdin);
    int n, kn_size;
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>kn_size;
        vec.push_back(make_pair(kn_size, 0));
    }
    for(int i = 0; i < n; ++i){
        pii itr;
        if(!vec[i].second) itr = b_s(i+1, n, vec[i].first);
        if(itr.first) vec[itr.second].second = 1;
    }
    int cnt = 0;
    for(int i = 0; i < n; ++i) if(!vec[i].second) cnt++;
    cout << cnt << endl;
    fclose(inp);
    return 0;
}
