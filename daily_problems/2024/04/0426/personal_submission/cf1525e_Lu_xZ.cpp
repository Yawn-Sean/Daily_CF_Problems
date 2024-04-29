#include<bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int N = 5e4 + 5, P = 998244353;

ll qpow(ll a, ll b) {
	ll ret = 1;
	while(b) {
		if(b & 1) ret = ret * a % P;
		b >>= 1;
		a = a * a % P;
	}
	return ret;
}

int n, m, d[N][30];
ll f[N];

int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> n >> m;
	for(int j = 1; j <= n; ++ j) {
		for(int i = 1; i <= m; ++ i) {
			cin >> d[i][j];
		}
	}
	
	ll inv = 1, fac = 1;
	for(int i = 1; i <= n; ++ i) fac = fac * i % P;
	inv = qpow(fac, P - 2);
	
	for(int i = 1; i <= m; ++ i) {
		sort(d[i] + 1, d[i] + n + 1);
		/*
		  pj \in [1, dj)
		 */
		f[i] = 1;
		
		for(int j = 1; j <= n; ++ j) {
			if(d[i][j] - 1 < j) {
				f[i] = 0;
				break;
			}
			f[i] = f[i] * (d[i][j] - j) % P;
		}
		f[i] = (f[i - 1] + fac - f[i]) % P; 
	}
	if(f[m] < 0) f[m] += P;
	
	cout << f[m] * inv % P;
	return 0;
}

/*
  x不被点亮的次数
*/
