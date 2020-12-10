// accepted

#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *inp = freopen("in.txt", "r", stdin);
    int n, num;
    vector<int>positiveSet, negetiveSet, zeroSet;
    cin>>n;
    for(int i = 0; i < n; ++i){
        cin>>num;
        if(!num) zeroSet.push_back(num);
        else if(num<0) negetiveSet.push_back(num);
        else positiveSet.push_back(num);
    }
    int posNum = positiveSet.size();
    int negNum = negetiveSet.size();
    int zeroNum = zeroSet.size();
    if(positiveSet.empty()){
        positiveSet.push_back(negetiveSet[--negNum]);
        positiveSet.push_back(negetiveSet[--negNum]);
        posNum += 2;
    }
    if(!(negNum&1)){
        zeroSet.push_back(negetiveSet[--negNum]);
        zeroNum++;
    }
    cout << negNum;
    for(int i = 0; i < negNum; ++i) cout << " " << negetiveSet[i];
    cout << endl;
    cout << posNum;
    for(int i = 0; i < posNum; ++i) cout << " " << positiveSet[i];
    cout << endl;
    cout << zeroNum;
    for(int i = 0; i < zeroNum; ++i) cout << " " << zeroSet[i];
    cout << endl;
    //fclose(inp);
    return 0;
}
