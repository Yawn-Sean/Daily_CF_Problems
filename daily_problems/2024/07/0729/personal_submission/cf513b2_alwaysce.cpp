#include <bits/stdc++.h>
using i64 = long long;

i64 mod = 998244353;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	i64 n, k;
	std::cin >> n >> k;
	--k;
	
	int l = 0, r = n - 1;
	std::vector<int> ans(n);
	
	for (int i = 1; i < n; i++) {
		// 0 <= k < 1 << (n - 1 - i) 前一半 ans[l]
		// 1 << (n - 1 - i) <= k 后一半 ans[r]
		if ( k >= (1ll << (n - 1 - i)) ) {
			ans[r--] = i;
			k -= (1ll << (n - 1 - i));
		} else {
			ans[l++] = i;
		}
	}
	ans[l] = n;
	for (auto& x: ans) {
		std::cout << x << ' ';
	}
	std::cout << '\n';
	return 0;
}
