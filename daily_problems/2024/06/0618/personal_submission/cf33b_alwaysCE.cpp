#include <bits/stdc++.h>
using i64 = long long;

int inf = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	std::string s, t;
	std::cin >> s >> t;
	
	int n;
	std::cin >> n;

	std::vector<std::vector<int> > f(26, std::vector<int>(26, inf));	
	for (int i = 0; i < n; i++) {
		char x, y;
		int cost;
		std::cin >> x >> y >> cost;
		f[(x - 'a')][(y - 'a')] = std::min(cost, f[(x - 'a')][(y - 'a')]);
	}
	for (int i = 0; i < 26; i++) {
		f[i][i] = 0;
	}
	
	if (s.size() != t.size()) {
		std::cout << -1 << '\n';
		return 0;
	}
	
	for (int k = 0; k < 26; k++) {
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < 26; j++) {
				f[i][j] = std::min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	
	std::string ans;
	i64 tot = 0;
	for (int i = 0; i < (int)s.size(); i++) {
		if (s[i] == t[i]) {
			ans.push_back(s[i]);
		} else {
			int change = inf, minCh = 0;
			for (int target = 0; target < 26; target++) {
				int tmp = f[s[i] - 'a'][target] + f[t[i] - 'a'][target];
				if (tmp < change) {
					change = tmp;
					minCh = target;
				}
			}
			
			if (change == inf) {
				std::cout << -1 << '\n';
				return 0;
			}
			
			tot += change;
			ans.push_back((char)('a' + minCh));
		}
	}
	
	std::cout << tot << '\n';
	std::cout << ans << '\n';
	
	return 0;
}
