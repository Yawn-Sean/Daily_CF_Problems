#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::pair<i64, i64>> v(n);
	for (int i = 0; i < n; i++) {
		std::cin >> v[i].first >> v[i].second;
	}
	std::sort(v.begin(), v.end());
	ld64 ans = 0;
	for (int i = 0; i < n; i++) {
		ld64 now = ((ld64)1 * v[i].first + v[i].first + std::log2(v[i].second));
		if (now >= ans) {
			ans = now;
		}
	}
	std::cout << std::max(v.back().first + 1, (i64)std::ceil(ans / 2)) << endl;
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int t = 1;
	while (t--) {
		solve();
	}
	return 0;
}
