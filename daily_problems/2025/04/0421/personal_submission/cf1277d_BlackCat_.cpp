#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;

void solve() {
	int n;
	std::cin >> n;
	std::vector<int> c0, c1, c01, c10;
	std::map<std::string, int > mp;
	std::vector<std::string> ss(n + 1);
	for (int i = 1; i <= n; i++) {
		std::string s;
		std::cin >> s;
		ss[i] = s;
		mp[s] = 1;
		if (s[0] == '0' && s[s.size() - 1] == '0') {
			c0.push_back(i);
		}
		else if (s[0] == '1' && s[s.size() - 1] == '1') {
			c1.push_back(i);
		}
		else if (s[0] == '0' && s[s.size() - 1] == '1') {
			c01.push_back(i);
		}
		else {
			c10.push_back(i);
		}
	}
	if (c0.size() != 0 && c1.size() != 0 && c01.size() == 0 && c10.size() == 0) {
		std::cout << -1 << endl;
		return ;
	}
	std::vector<int> ans;
	if (c01.size() > c10.size() + 1) {
		int need = (c01.size() - c10.size()) / 2;
		int cnt = 0;
		for (int i = 0; i < c01.size() ; i++) {
			std::string s1 = ss[c01[i]];
			std::reverse(s1.begin(), s1.end());
			if (mp.find(s1) == mp.end()) {
				ans.push_back(c01[i]);
				cnt++;
				if (cnt == need) {
					break;
				}
			}

		}
		if (cnt < need) {
			std::cout << -1 << endl;
			return ;
		}
	}
	else if (c10.size() > c01.size() + 1) {
		int need = (c10.size() - c01.size()) / 2;
		int cnt = 0;
		for (int i = 0; i < c10.size() ; i++) {
			std::string s1 = ss[c10[i]];
			std::reverse(s1.begin(), s1.end());
			if (mp.find(s1) == mp.end()) {
				ans.push_back(c10[i]);
				cnt++;
				if (cnt == need) {
					break;
				}
			}

		}
		if (cnt < need) {
			std::cout << -1 << endl;
			return ;
		}
	}
	std::cout << ans.size() << endl;
	for (auto x : ans) {
		std::cout << x << " ";
	}
	std::cout << endl;
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	int t = 1;
	std::cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}
