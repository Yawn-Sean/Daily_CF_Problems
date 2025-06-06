#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;

void solve() {
	int n, m;
	std::cin >> n >> m;
	int cnt = 0;
	std::vector<std::array<i64, 3>> a(m);
	for (int i = 0; i < m; i++) {
		std::cin >> a[i][0] >> a[i][1];
		cnt += a[i][1];
		a[i][2] = i;
	}
	std::vector<std::pair<int, int>> ans(m);
	if (cnt != n - 1 ) {
		std::cout << -1 << endl;
		return ;
	}
	std::sort(a.begin(), a.end(), [&](std::array<i64, 3>&a1, std::array<i64, 3>&a2) {
		return a1[0] * 2 + (1 - a1[1]) < a2[0] * 2 + (1 - a2[1]);
	});
	int cur = 2;
	int u = 2;
	int v1 = 1;
	for (auto [v, b, idx] : a) {
		if (b) {
			ans[idx].first = 1;
			ans[idx].second = cur++;
		}
		else {
			v1++;
			if (v1 == u) {

				u++;
				v1 = 2;
			}
			if (u >= cur) {
				std::cout << -1 << endl;
				return ;
			}
			ans[idx].first = u;
			ans[idx].second = v1;
		}
	}
	for (auto [x, y] : ans) {
		std::cout << x << " " << y << endl;
	}
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
