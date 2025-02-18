#include <bits/stdc++.h>

using i64 = long long;
using ui64 = unsigned long long;

i64 inf = 1E18;
i64 mod = 1000000007;

i64 pow(i64 base, i64 exp, i64 mod) {
	i64 res = 1;
	while (exp) {
		if (exp & 1) {
			res = (res * base) % mod;
		}
		base = (base * base) % mod;
		exp >>= 1;
	}
	return res;
}

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, k;
	std::cin >> n >> k;
	
	std::vector<i64> f(n + 1, 1), inv_f(n + 1, 1);
	for (int i = 1; i <= n; i++) {
		f[i] = f[i - 1] * i % mod;
	}
	inv_f[n] = pow(f[n], mod - 2, mod);
	
	for (int i = n; i > 0; i--) {
		inv_f[i - 1] = inv_f[i] * i % mod;
	}
	
	std::map<int,int> dif;
	for (int i = 0; i < n; i++) {
		int l, r;
		std::cin >> l >> r;
		dif[l]++;
		dif[r + 1]--;
	}
	
	auto comb = [&](int n, int m) {
		i64 tmp = (f[n] * inv_f[m]) % mod;
		tmp = (tmp * inv_f[n - m]) % mod;
		return tmp;
	};

	int last = 0, cur = 0;
	i64 ans = 0;
	for (auto& [key, v]: dif) {
		if (cur >= k) {
			// [last, key)
			ans = (ans + 1ll * (key - last) * comb(cur, k) % mod);
			ans %= mod;
		}
		last = key;
		cur += v;
	}
	std::cout << ans << '\n';
	return 0;
}
