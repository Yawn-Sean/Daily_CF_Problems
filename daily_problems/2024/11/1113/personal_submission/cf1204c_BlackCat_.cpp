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
	std::vector<std::vector<int>> e(n);
	for (int i = 0; i < n; i++) {
		std::string s;
		std::cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == '1') {
				e[i].push_back(j);
			}
		}
	}
	int k;
	std::cin >> k;
	std::vector<int> a(k);
	std::vector<std::vector<int>> vis(n, std::vector<int>(n, 1e9));
	for (int i = 0; i < n; i++) {
		vis[i][i] = 0;
		for (auto v : e[i]) {
			vis[i][v] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				vis[j][k] = std::min(vis[j][k], vis[j][i] + vis[i][k]);
			}
		}
	}
	for (int i = 0; i < k; i++) {
		std::cin >> a[i];
		a[i]--;
	}
	std::set<int> s;
	std::vector<int> ans;
	ans.push_back(a[0]);
	int st = a[0];
	for (int i = 1; i < k; i++) {
		if (vis[st][a[i]] != vis[st][a[i - 1]] + vis[a[i - 1]][a[i]]) {
			ans.push_back(a[i - 1]);
			st = a[i - 1];
		}
	}
	ans.push_back(a[k - 1]);
	std::cout << ans.size() << endl;
	for (auto v : ans) {
		std::cout << v + 1 << " ";
	}

}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
