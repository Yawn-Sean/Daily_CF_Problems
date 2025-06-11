#include <bits/stdc++.h>
using i64 = long long;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int l, r, x, y;
	std::cin >> l >> r >> x >> y;
	
	// (k1,k2)互质且 k1k2=y/x的数量求解
	// k1,k2 属于 [l/x, r/x]
	if (y % x != 0) {
		std::cout << 0 << '\n';
		return 0;
	}
	y /= x;
	
	int ans = 0;
	if (l <= 1*x and 1*x <= r and l <= y*x and y*x <= r) {
		ans += (1 == y ? 1: 2);
	}
	
	for (int i = 2; i * i <= y; i++) {
		if (y % i == 0) {
			int f1 = i;
			int f2 = y / i;
			bool same = (f1 == f2);
			if (std::gcd(f1, f2) == 1 and l <= f1*x and f1*x <= r and l <= (f2 * x) and (f2 * x) <= r) {
				ans += (same ? 1: 2);
			}
		}	
	}
	
	std::cout << ans << '\n';
	return 0;
}
