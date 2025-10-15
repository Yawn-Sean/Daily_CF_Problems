#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;

void solve() {
	int n;
	std::cin >> n;
	std::map<std::string, int> mp;
	std::string s, x, y;
	mp["void"] = 0;
	for (int i = 0; i < n; i++) {
		std::cin >> s;

		if (s[4] == 'o') {
			std::cin >> x;
			int j = 0;
			int count = 0;
			while (j < x.size() && x[j] == '&') {
				count--;
				j++;
			}
			int h = x.size() - 1;
			while (h >= 0 && x[h] == '*') {
				count++;
				h--;
			}
			std::string fu(x.begin() + j, x.begin() + h + 1);
			int m;
			if (mp.find(fu) == mp.end()) {
				m = -1e9;
			}
			else {
				m = mp[fu] + count;
			}
			if (m < 0) {
				std::cout << "errtype" << endl;
			}
			else {
				std::cout << "void";
				for (int j = 0; j < m; j++) {
					std::cout << "*";
				}
				std::cout << endl;
			}
		}
		else {
			std::cin >> x >> y;
			int count = 0;
			int j = 0;
			while (j < x.size() && x[j] == '&') {
				count--;
				j++;
			}
			int h = x.size() - 1;
			while (h >= 0 && x[h] == '*') {
				count++;
				h--;
			}
			std::string fu(x.begin() + j, x.begin() + h + 1);
			if (fu == "void") {
				mp[y] = count >= 0 ? count : -1e9;
			}
			else {
				if (mp.find(fu) == mp.end()) {
					mp[y] = -1e9;
				}
				else {
					mp[y] = count + mp[fu] >= 0 ? count + mp[fu] : -1e9;
				}

			}
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
