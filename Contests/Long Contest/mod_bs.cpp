#include <bits/stdc++.h>
using namespace std;
int arr[] = {1};
pair<int,int> b_s(int low, int high, int key){
    if(arr[high]<key) return make_pair(-1,high);
    int mid;
    while(low<=high){
        mid = low+(high-low)/2;
        if(arr[mid]==key) return make_pair(1,mid);
        else if(arr[mid]<key) low = mid+1;
        else high = mid-1;
    }
    for(int i = high>low? low:high; ; ++i) if(arr[i]>key) return make_pair(0, i);
}

int main(){
    pair<int, int> a = b_s(0, 0, 1);   // low index, high index, key
    cout << a.first << "  " << a.second << endl;
    return 0;
}
