#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> a(n);
	for (int i = 0; i < n; i++) {
		std::cin >> a[i];
	}
	std::vector<int> xiu;
	auto check = [&](int i)->bool{
		if (i & 1) {
			return a[i] > a[i + 1];
		}
		else{
			return a[i] < a[i + 1];
		}
	};
	for (int i = 0; i < n - 1; i++) {
		if (!check(i)) {
			xiu.push_back(i);
		}
	}
	if (xiu.size() > 4) {
		std::cout << 0 << endl;
		return ;
	}
	int ans = 0;
	std::map<int, std::map<int, int>>mp;
	for (auto x : xiu) {
		for (int j = 0; j < n; j++) {
			if (j == x) {
				continue;
			}
			int flag = 0;
			std::swap(a[j], a[x]);
			if (x != 0) {
				if (!check(x - 1)) {
					flag = 1;
				}
			}
			if (!check(x)) {
				flag = 1;
			}
			if (j != 0) {
				if (!check(j - 1)) {
					flag = 1;
				}

			}
			if (j != n - 1 && !check(j)) {
				flag = 1;
			}
			for (auto y : xiu) {
				if (!check(y)) {
					flag = 1;
				}
			}
			std::swap(a[j], a[x]);
			if (flag) {
				continue;
			}
			if (mp[j][x] == 1 || mp[x][j] == 1) {
				continue;
			}
			ans++;
			mp[j][x] = 1;

		}
		if (x != n - 1) {
			for (int j = 0; j < n; j++) {
				if (j == x + 1 || j == x) {
					continue;
				}
				int flag = 0;
				std::swap(a[j], a[x + 1]);
				if (x + 1 != 0) {
					if (!check(x)) {
						flag = 1;
					}
				}
				if (x + 1 != n - 1 && !check(x + 1)) {
					flag = 1;
				}
				if (j != 0) {
					if (!check(j - 1)) {
						flag = 1;
					}

				}
				if (j != n - 1 && !check(j)) {
					flag = 1;
				}
				for (auto y : xiu) {
					if (!check(y)) {
						flag = 1;
					}
				}
				std::swap(a[j], a[x + 1]);
				if (flag) {
					continue;
				}
				if (mp[j][x + 1] == 1 || mp[x + 1][j] == 1) {
					continue;
				}
				ans++;
				mp[j][x + 1] = 1;
			}
		}
	}
	std::cout << ans << endl;
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
