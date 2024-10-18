#include <bits/stdc++.h>

using i64 = long long;
using ui64 = unsigned long long;

i64 inf = 1E18;
int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;
	std::cin >> n;
	
	std::vector<int> a(n);
	std::vector<std::vector<int>> tmp(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
		a[i] = std::min(a[i], n) - 1;
		// >= a[i]的位置
		tmp[a[i]].push_back(i);
	}
	
	Fenwick<int> fen(n + 1);
	i64 ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		// 固定x 找y 满足x < y <= a[x] 且 a[y] >= x
		// >=x的位置
		for (auto& x: tmp[i]) {
			fen.add(x, 1);
		}
		// (x, a[x]] 区间上y的个数
		if (a[i] > i) {
			ans += fen.rangeSum(i + 1, a[i] + 1);
		}
	}
	std::cout << ans << '\n';
	return 0;
}
