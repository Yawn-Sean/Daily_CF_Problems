#include <bits/stdc++.h>

using i64 = long long;
using ui64 = unsigned long long;

i64 inf = 1E18;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int a, b;
	std::cin >> a >> b;
	if (a < b) {
		std::cout << -1 << '\n';
	} else {
		double ans = 1e9;
		// 2x 4x ... 2kx
		int kx = (a - b);
		if (kx >= b * 2) {
			int k = kx / (2 * b);
			ans = std::min(ans, 1.0 * kx / 2 / k);
		}
		kx = a + b;
		if (kx >= b * 2) {
			int k = kx / (2 * b);
			ans = std::min(ans, 1.0 * kx / 2 / k);
		}
		std::cout << std::fixed << std::setprecision(12) << ans << '\n';
	}
	
	return 0;
}
