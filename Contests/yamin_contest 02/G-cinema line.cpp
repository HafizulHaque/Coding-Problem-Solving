// accepted
#include <bits/stdc++.h>
using namespace std;

int main(){
    //FILE *inp = freopen("input.txt", "r", stdin);
    int n;
    cin>>n;
    int fiftyCount = 0, twentyFiveCount = 0, possibility = 1, currency;
    while(n--){
        cin>>currency;
        if(possibility){
            // in case of currency 25
            if(currency==25){
                twentyFiveCount++;
            }
            // in case of currency 50
            else if(currency==50){
                if(twentyFiveCount==0) possibility = 0;
                else{
                    twentyFiveCount--;
                    fiftyCount++;
                }
            }
            // in case of currency 100
            else if(currency==100){
                if(twentyFiveCount==0) possibility = 0;
                else if(fiftyCount==0&&twentyFiveCount<3) possibility = 0;
                else if(fiftyCount != 0){
                    fiftyCount--;
                    twentyFiveCount--;
                }
                else{
                    twentyFiveCount -= 3;
                }
            }

        }   // possibility check if

    }   // while ends

    if(possibility) cout << "YES" << endl;
    else cout << "NO" << endl;
    //fclose(inp);
    return 0;
}
