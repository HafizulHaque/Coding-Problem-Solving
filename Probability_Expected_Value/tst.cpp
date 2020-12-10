#include <bits/stdc++.h>
#define LL long long
using namespace std;
vector<LL> Fact;
vector<LL> Invfact;
vector<LL> Inv;

//Preprocessing factorial and its inverses in O(p) time.
void compute(int P)
{
	Fact.clear();
	Invfact.clear();
	Fact.resize(P);
	Invfact.resize(P);
	Inv.clear();
    Inv.resize(P);

	Fact[0]=Fact[1]=1;
	Invfact[0]=Invfact[1]=1;
	Inv[0]=1;
    Inv[1]=1;

	for(int i=2;i<P;i++)
	{
		Fact[i]=(Fact[i-1]*i)%P;
		Inv[i]=((P-P/i)*Inv[P%i])%P;
	}
}

//Computes C(N,R) modulo P in O(log(n)) time.
LL Lucas(LL N,LL R,int P)
{
	if(R<0||R>N)
	{
		return 0;
	}

	if(R==0||R==N)
	{
		return 1;
	}

	if(N>=P)
	{
		return (Lucas(N/P,R/P,P)*Lucas(N%P,R%P,P))%P;
	}

	return (Fact[N]*(Invfact[N-R]*Invfact[R])%P)%P;
}

int main()
{
    int n, r, md=1000000007;
    compute(md);
    while(cin>>n>>r){
        cout<<Lucas(n, r, md)<<endl;
    }
}
