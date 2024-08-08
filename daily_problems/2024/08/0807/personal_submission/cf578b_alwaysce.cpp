#include <bits/stdc++.h>
using i64 = long long;
i64 mod = 1000000007;
i64 inf = 1e18;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n, k, x;
	std::cin >> n >> k >> x;
	std::vector<i64> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	
	i64 ans = 0;
	std::vector<i64> suf(n + 1, 0);
	for (int i = n - 1; i >= 0; i--) {
		suf[i] = (suf[i + 1] | a[i]);
	}
	i64 pre = 0;
	for (int i = 0; i < n; i++) {
		i64 tmp = a[i] * pow(x, k);
		tmp |= pre;
		if (i + 1 < n) {
			tmp |= suf[i + 1];
		}
		ans = std::max(ans, tmp);
		pre |= a[i];
	}
	std::cout << ans << '\n';
	return 0;
}
