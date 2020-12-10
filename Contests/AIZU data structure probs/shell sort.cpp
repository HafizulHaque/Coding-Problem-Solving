// accepted

#include <bits/stdc++.h>
using namespace std;
int cnt = 0;
vector<long>gap_list;

void insertion_sort(long A[], int n, int g){
    for(int i = g; i <= n-1; ++i){
        int v = A[i];
        int j = i-g;
        while(j>=0&&A[j]>v){
            A[j+g] = A[j];
            j = j-g;
            cnt++;
        }
        A[j+g] = v;
    }
}

void shell_sort(long A[], int n, int m){
    for(int i = m-1; i >= 0; --i){
        insertion_sort(A, n, gap_list[i]);
    }
    return;
}

int main(){
    //FILE *inp = freopen("inp.txt", "r", stdin);
    int n;
    scanf("%d", &n);
    long arr[n];
    for(int i = 0; i < n; ++i) scanf("%ld", &arr[i]);
    for(int i = 1; i*i <= n; ++i){
        gap_list.push_back(i*i);
        if(gap_list.size()>=100)break;
    }
    int gap_cnt = gap_list.size();
    cout << gap_cnt << endl;
    for(int i = gap_cnt-1; i >=0; --i){
        if(i != gap_cnt-1) printf(" ");
        printf("%ld", gap_list[i]);
    }
    printf("\n");
    shell_sort(arr, n, gap_cnt);
    printf("%d\n", cnt);
    for(int i = 0; i < n; ++i){
        printf("%ld\n",arr[i]);
    }
    //fclose(inp);
    return 0;
}
