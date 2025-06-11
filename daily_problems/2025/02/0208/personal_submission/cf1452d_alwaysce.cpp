#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 998244353;

i64 pow(i64 a, i64 b, i64 mod) {
    i64 res = 1ll;
    a %= mod;
    while (b) {
    	if (b&1) {
    		res = res * a % mod;
    	}
    	a = a * a % mod;
    	b>>=1;
    }
    return res;
}

i64 inv(i64 x) {
	return pow(x, mod - 2, mod);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	
	vector<i64> fac(n+1,1), inv_fac(n+1,1);
	fac[0] = fac[1] = 1ll;
	for (int i = 2; i <= n; i++) {
		fac[i] = 1ll * i * fac[i - 1] % mod;
		inv_fac[i] = inv(fac[i]);
	}

	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		if ((n - i) % 2) continue;
		
		int rx = (n - i) / 2; // r
		int nx = i; // n
		ans += ((fac[nx+rx-1] * inv_fac[nx - 1]) % mod * inv_fac[rx]) % mod;
		ans %= mod;
	}
	
	ans = ans * inv(pow(2ll, n, mod)) % mod;
	cout << ans % mod;
	return 0;
}
