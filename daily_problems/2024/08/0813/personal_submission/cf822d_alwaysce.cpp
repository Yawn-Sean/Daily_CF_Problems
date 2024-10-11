#include <bits/stdc++.h>

using i64 = long long;
using ui64 = unsigned long long;

i64 inf = 1E18;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	i64 t, l, r;
	std::cin >> t >> l >> r;
	
	int mx = 5E6;
	std::vector<i64> mn_fac(mx + 1), f(mx + 1);
	std::iota(mn_fac.begin(), mn_fac.end(), 0);
	
	for (int i = 2; i <= 4000; i++) {
		if (mn_fac[i] == i) {
			for (int j = i * i; j <= mx; j += i) {
				if (mn_fac[j] == j) {
					mn_fac[j] = i;
				}
			}
		}
	}
	
	for (int i = 2; i <= mx; i++) {
		i64 cost = (1ll * i * (mn_fac[i] - 1) / 2) % mod;
		f[i] = (f[i / mn_fac[i]] + cost) % mod;
	}
	
	i64 ans = 0;
	for (int i = r; i >= l; i--) {
		ans = (((ans * t) % mod) + f[i]) % mod;
		ans %= mod;
	}
	std::cout << ans << '\n';
	return 0;
}
