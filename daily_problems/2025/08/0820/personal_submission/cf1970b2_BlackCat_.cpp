#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::pair<int, int>> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i].first;
		a[i].second = i;
	}
	std::sort(a.begin(), a.end(), std::greater<>());
	std::vector<std::array<int, 3>> ans(n);
	ans[0] = {1, 1, 1};
	int lx = 1;
	int ly = 1;
	for (int i = 0; i < n - 1; i++) {
		if (a[i].first == 0) {
			ans[a[i].second] = {1, i + 2, a[i].second + 1};
			lx = ans[a[i].second][0];
			ly = i + 2;
			continue;
		}
		int fw1 = i + 1;
		if (a[i].first >= fw1) {
			int w = a[i].first - fw1;
			ans[a[i].second] = {1 + w, i + 2, 1};
		}
		else {
			a[i].first -= 1;
			int x;
			if (lx + a[i].first > n) {
				x = lx - a[i].first;
			}
			else {
				x = lx + a[i].first;
			}
			ans[a[i].second] = {x, i + 2, a[i - 1].second + 1};
		}
		lx = ans[a[i].second][0];
		ly = i + 2;
	}
	std::cout << "YES" << endl;
	for (int i = 0; i < n; i++) {
		std::cout << ans[i][1] << " " << ans[i][0] << endl;
	}
	for (int i = 0; i < n; i++) {
		std::cout << ans[i][2] << " \n"[i == n - 1];
	}
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
