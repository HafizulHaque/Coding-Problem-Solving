// accepted

#include <bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
int arr[50002];

pii b_search(int key, int beg, int lst){
    pii ret;
    ret.first = ret.second = -1;
    int st = beg, en = lst, mid;
    while(st<=en){
        mid = st+(en-st)/2;
        if(arr[mid]==key){
            break;
        }
        else if(key>arr[mid]) st = mid+1;
        else en = mid-1;
    }
    if(arr[mid]==key){
        //cout << "mid found at index " << mid << endl;
        if(mid==beg) ret.first = -1; // ret.first set to -1
        else{
            int temp = mid;
            while(temp-1>=beg&&arr[temp-1]==key){
                temp--;
            }
            if(temp!=beg) ret.first = temp-1;
        }

        if(mid==lst);// ret.second set to -1
        else{
            int temp = mid;
            while(temp+1<=lst&&arr[temp+1]==key){
                temp++;
            }
            if(temp!=lst) ret.second = temp+1;
        }
    }
    else{
        //cout << "mid not matched with key. mid returned " << mid << endl;
        if(arr[mid]<key){
            ret.first = mid;
            //cout << "ret.first initialized by index " << mid << endl;
        }
        else{
            ret.second = mid;
            //cout << "ret.second initialized by index " << mid << endl;
        }
        int temp;
        if(ret.first==-1){
            //cout << "finding ret.first" << endl;
            temp = mid;
            while(temp-1>=beg&&arr[temp-1]>=key){
                temp--;
            }
            if(temp!=beg) ret.first = temp-1;
            //cout << "ret.first found at " << ret.first << endl;
        }
        if(ret.second==-1){
            //cout << "finding ret.second" << endl;
            temp = mid;
            while(temp+1<=lst&&arr[temp+1]<=key){
                temp++;
            }
            if(temp!=lst) ret.second = temp+1;
            //cout << "ret.second found at " << ret.second << endl;
        }
    }
    return ret;
}

int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    //FILE *out = freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(0);
    int n, q, key;
    pii ans;
    cin>>n;
    for(int i = 0; i < n; ++i) cin>>arr[i];
    cin>>q;
    while(q--){
        cin>>key;
        ans = b_search(key, 0, n-1);
        ans.first==-1? cout << "X " : cout << arr[ans.first] << " ";
        ans.second==-1? cout << "X" : cout << arr[ans.second];
        cout << endl;
    }
    //fclose(inp);
    //fclose(out);
    return 0;
}
