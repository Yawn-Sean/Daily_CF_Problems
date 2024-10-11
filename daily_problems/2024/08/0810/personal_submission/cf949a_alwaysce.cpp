#include <bits/stdc++.h>

using i64 = long long;
using ui64 = unsigned long long;

i64 inf = 1E18;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::string s;
	std::cin >> s;
	
	int n = (int)s.size();
	std::vector<int> p0, p1;
	std::vector<std::vector<int>> ans;
	
	for (int i = 0; i < n; i++) {
		if (s[i] == '1') {
			if (p0.size() > 0) {
				p1.push_back(p0.back());
				p0.pop_back();
				ans[p1.back()].push_back(i + 1);
			} else {
				std::cout << -1 << '\n';
				return 0;
			}
		} else {
			if (p1.size() > 0) {
				p0.push_back(p1.back());
				p1.pop_back();
				ans[p0.back()].push_back(i + 1);
			} else {
				p0.push_back(ans.size());
				ans.push_back({i + 1});
			}
		}
	}
	
	if (p1.size()) {
		std::cout << -1 << '\n';
	} else {
		std::cout << ans.size() << '\n';
		for (auto& l: ans) {
			std::cout << l.size() << ' ';
			for (auto& x: l) {
				std::cout << x << ' ';
			}
			std::cout << '\n';
		}
	}
	
	return 0;
}
