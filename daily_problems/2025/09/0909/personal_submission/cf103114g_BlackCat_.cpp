#include<bits/stdc++.h>
// #define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
using i128 = __int128;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> pos(n + 1);
	for (int i = 0; i < 10; i++) {
		std::vector<int> s;
		for (int j = 0; j < n; j++) {
			if ((j >> i) & 1) {
				s.push_back(j + 1);
			}
		}
		if (!s.empty()) {
			std::cout << s.size() << " ";
			for (auto x : s) {
				std::cout << x << " ";
			}
			std::cout << std::endl;
			int x;
			for (int j = 0; j < s.size(); j++) {
				std::cin >> x;
				pos[x] |= (1 << i);
			}
		}
	}
	std::vector<int> ans(n);
	for (int i = 1; i <= n; i++) {
		ans[pos[i]] = i;
	}
	std::cout << "! ";
	for (int i = 0; i < n; i++) {
		std::cout << ans[i] << " ";
	}
	std::cout << std::endl;
}
signed main() {
	// std::ios::sync_with_stdio(0);
	// std::cin.tie(0);
	// std::cout.tie(0);
	int t = 1;
	// std::cin>>t;
	while (t--) {
		solve();
	}
	return 0;
}
