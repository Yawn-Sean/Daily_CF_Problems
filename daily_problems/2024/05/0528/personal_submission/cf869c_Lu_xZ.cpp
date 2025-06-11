// LUOGU_RID: 156571817
#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int P = 998244353, N = 5005;


ll qpow(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % P;
		b >>= 1;
		a = a * a % P;
	}
	return ret;
}

ll inv[N], fac[N];

void init() {
	fac[0] = 1;
	for(int i = 1; i <= 5000; ++ i) fac[i] = fac[i - 1] * i % P;
	inv[5000] = qpow(fac[5000], P - 2);
	for(int i = 5000; i >= 1; -- i) inv[i - 1] = inv[i] * i % P;
}

ll C(int n, int m) {
	if(m > n) return 0;
	return fac[n] * inv[m] % P * inv[n - m] % P;
}

ll get(int n, int m) {
	if(n > m) swap(n, m);
	ll tmp = 0;
	for(int i = 0; i <= n; ++ i) tmp = (tmp + C(n, i) * C(m, i) % P * fac[i]) % P;
	return tmp;
}

void solve() {
	ll a, b, c; cin >> a >> b >> c;
	init();
	cout << get(a, b) * get(a, c) % P * get(b, c) % P;
}

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	int T = 1;
	
	while(T --) {
		solve();
	}
	return 0;
}
