#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int mod=1e9+7;
LL qmi(LL a, LL b, LL q){
	LL res=1%q;
	while(b){
		if(b&1) res=(res*a)%q;
		a=(LL)a*a%q;
		b>>=1; 
	}
	return res;
}
int main(){
	LL x, k;
	cin>>x>>k;
	if(x==0){
		cout<<0; 
		return 0;
	}
	x%=mod;
	LL k2=qmi(2, k, mod);
	cout<<((x*k2%mod+((x-1)*k2%mod+1)%mod)+mod)%mod;
	return 0;
}
