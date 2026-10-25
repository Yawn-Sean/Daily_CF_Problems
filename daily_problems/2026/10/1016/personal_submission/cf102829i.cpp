#include <bits/stdc++.h>
using namespace std;
//#define int long long
#define endl "\n"
using LL=long long;using ll=long long;
//向下x,向左y，方案数C(x+y,x)
const LL MOD=1e9+7;
const int MXN = 2e6 + 10; 
LL qpow(LL x,LL y){
	LL res=1;
	while(y){
		if(y&1)res=res*x%MOD;
		x=x*x%MOD;
		y>>=1;
	}
	return res;
}
ll fact[MXN];   
ll infact[MXN]; 
void init() {
    fact[0] = 1;
    infact[0] = 1;
    for (int i = 1; i < MXN; i++) fact[i] = fact[i - 1] * i % MOD;
    infact[MXN - 1] = qpow(fact[MXN - 1], MOD - 2);
    for (int i = MXN - 2; i >= 1; i--)infact[i] = infact[i + 1] * (i + 1) % MOD;
}
ll C(int n, int m) {
    if (m < 0 || m > n) return 0;
    return fact[n] * infact[m] % MOD * infact[n - m] % MOD;
}
ll A(int n, int m) {
    if (m < 0 || m > n) return 0;
    return fact[n] * infact[n - m] % MOD;
}

void solve() {
	int x,y;
	cin>>x>>y;
	x=abs(x),y=abs(y);
	cout<<(C(x+y+2,y+1)-C(y+1,y+1)+MOD)%MOD<<endl;
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int loop = 1;
	cin >> loop;
	init();
	while (loop--){
		solve();
	}
	return 0;
}
