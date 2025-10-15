#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;
using i128 = __int128;

void solve() {
	int n;
	std::cin >> n;
	std::vector<std::vector<int>> a(n);
	int res = 0;
	i64 sum = 0;
	for (int i = 0; i < n; i++) {
		int k, a1, x, y, m;
		std::cin >> k >> a1 >> x >> y >> m;
		sum += k;
		x %= m;
		y %= m;
		int res1 = 0;
		a[i].push_back(a1);
		for (int j = 1; j < k; j++) {
			int a2 = (1ll * a1 * x % m + y) % m;
			if (a2 < a1) {
				res1++;

			}
			a[i].push_back(a2);
			a1 = a2;
		}
		res = std::max(res, res1);
	}
	if (sum > 200000) {
		std::cout << res << endl;
		return ;
	}
	std::vector<std::vector<std::pair<int, int>>> duan(res + 1);
	for (int i = 0; i < n; i++) {
		int a1 = a[i][0];
		int res1 = 0;
		for (auto &a2 : a[i]) {

			if (a2 < a1) {
				res1++;
			}
			duan[res1].push_back({a2, i + 1});
			a1 = a2;
		}
	}
	std::cout << res << endl;
	for (int i = 0; i <= res; i++) {
		std::sort(duan[i].begin(), duan[i].end());
		for (auto [x, y] : duan[i]) {
			std::cout << x << " " << y << endl;
		}
	}
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
