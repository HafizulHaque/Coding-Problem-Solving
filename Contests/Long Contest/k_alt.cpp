#include <bits/stdc++.h>
using namespace std;

int main(){
    FILE *inp = freopen("in.txt", "r", stdin);
    char str[210];
    char temp[] = "Sandro";
    gets(str);
    int size = strlen(str);
    int _min = 10000;
    int val = 0;
    for(int i = 0; i <= size-6; ++i){
        for(int j = 0; j < 6; ++j){
            if(str[i+j]==temp[j]) continue;
            char ch = str[i+j];
            if(j){
                if(isupper(str[i+j])){
                    ch = tolower(str[i+j]);
                    val += 5;
                }
            }
            else{
                if(islower(str[i+j])){
                    ch = toupper(str[i+j]);
                    val += 5;
                }
            }
            if(ch != temp[j]) val += 5;
        }
        _min = _min<val? _min : val;
        val = 0;
    }
    cout << _min << endl;
    //fclose(inp);
    return 0;
}
