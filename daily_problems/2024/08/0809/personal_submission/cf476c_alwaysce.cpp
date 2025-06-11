#include <bits/stdc++.h>

using i64 = long long;
using ui64 = unsigned long long;

i64 inf = 1E18;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	i64 a, b;
	std::cin >> a >> b;
	
	i64 ans = 0;
	for (int r = 1; r <= b - 1; r++) {
		ans = (ans + (((b * r) % mod) * (((1ll + a) * a / 2) % mod) % mod)) % mod;
		ans = (ans + a * r) % mod;
	}
	std::cout << ans % mod << '\n';
	return 0;
}
