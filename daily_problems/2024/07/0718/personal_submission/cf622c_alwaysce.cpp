#include <bits/stdc++.h>
using i64 = long long;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
		
	int n, m;
	std::cin >> n >> m;
	
	std::vector<int> a(n), left(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		if (i > 0) {
			left[i] = (a[i] == a[i - 1] ? left[i - 1]: i);
		}
	}
	
	for (int j = 0; j < m; j++) {
		int l, r, x;
		std::cin >> l >> r >> x;
		--l; --r;
		if (a[r] != x) {
			std::cout << r + 1 << '\n';
		} else if (left[r] > l) {
			std::cout << left[r] << '\n';
		} else {
			std::cout << -1 << '\n';
		}
		
	}
	return 0;
}
