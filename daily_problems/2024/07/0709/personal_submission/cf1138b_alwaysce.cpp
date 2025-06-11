#include <bits/stdc++.h>
using i64 = long long;
i64 mod = 1000000007;

int main() {
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	
	int n;
	std::cin >> n;
	std::string s, t;
		
	std::cin >> s;
	std::cin >> t;
	
	std::vector<std::vector<int>> tmp(3);
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		cnt += (s[i] == '1');
		tmp[(s[i] - '0') + (t[i] - '0')].push_back(i+1);
	}
	
	for (int i2 = 0; i2 <= (int)tmp[2].size(); i2++) {
		int i1 = cnt - i2 * 2, i0 = n / 2 - i1 - i2;
		if (i0 >= 0 and i0 <= (int)tmp[0].size() and i1 >= 0 and i1 <= (int)tmp[1].size()) {
			for (int i = i0; i < (int)tmp[0].size(); i++) { std::cout << tmp[0][i] << ' '; }
			for (int i = i1; i < (int)tmp[1].size(); i++) { std::cout << tmp[1][i] << ' '; }
			for (int i = i2; i < (int)tmp[2].size(); i++) { std::cout << tmp[2][i] << ' '; }
			std::cout << '\n';
			return 0;
		}	
	}
	
	std::cout << -1 << '\n';
	return 0;
}
