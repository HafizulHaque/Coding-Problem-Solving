#include <bits/stdc++.h>
using namespace std;
int n;
double certo;
double tam[100010];
double achar(){
    double ini=0,fim=10000;
    while(ini-fim<=ZERO){
        double meio=(ini+fim)/2;
        double sum=0;
        for(int i=0;i<n;i++){
            double dif=tam[i]-meio;
            dif=max(dif,0.0);
            sum+=dif;
        }
        if(fabs(sum-certo)<=ZERO){
            return meio;
        }
        else if(sum-certo>ZERO){
            ini=meio;
        }
        else if(sum-certo<ZERO){
            fim=meio;
        }
    }
    return -1.0;
}
int main(){
    FILE *inp = freopen("inp.txt", "r", stdin);
    while(1){
        scanf("%d %lf",&n,&certo);
        if(n==0 && certo==0) break;
        int sum=0;
        for(int i=0;i<n;i++){
            scanf("%lf",&tam[i]);
            sum+=tam[i];
        }
        if(sum==certo)printf(":D\n");
        else{
            double res=achar();
            if(res!=-1.0)printf("%.4lf\n",res);
            else printf("-.-\n");
        }
    }
    fclose(inp);
    return 0;
}

