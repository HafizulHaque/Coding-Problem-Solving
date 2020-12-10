#include <bits/stdc++.h>
using namespace std;
typedef struct Interval{
    int nodeNo;
    int type; // 0 for opening, 1 for closing
    bool operator <(const Interval &a){
        if(nodeNo < a.nodeNo) return true;
        else if(nodeNo == a.nodeNo){
            return type<a.type;
        }
        else return false;
    }
};
Interval makeInterval(int no, int type){
    Interval temp;
    temp.nodeNo = no;
    temp.type = type;
    return temp;
}
string str;
vector<Interval>intervals;
stack<int> st;

int main(){
    int len;
    cin>>str;
    len = str.length();
    for(int i = 0; i < len; ++i){
        int l = i, r = i, l1 = i, r1 = i+1;
        while(l>=0&&r<len){
            if(str[l]==str[r]){
                intervals.push_back(makeInterval(l--,0));
                intervals.push_back(makeInterval(r++, 1));
            }
            else break;
        }
        while(l1>=0&&r1<len){
            if(str[l1]==str[r1]){
                intervals.push_back(makeInterval(l1--,0));
                intervals.push_back(makeInterval(r1++, 1));
            }
            else break;
        }
    }
    sort(intervals.begin(), intervals.end());
    /*for(auto itr = intervals.begin(); itr != intervals.end(); ++itr){
        cout << itr->nodeNo << "  " << itr->type << endl;
    }*/
    len = intervals.size();
    int cnt = 0;
    for(auto i = 0; i < len; ++i){
        if(intervals[i].type==0){
            st.push(intervals[i].nodeNo);
        }
        else{
            //int top = st.top();
            st.pop();
            if(st.empty()) cnt++;//cout << str.substr(top,intervals[i].nodeNo) << " ";
        }
    }
    cout << cnt << endl;
    return 0;
}
