#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;

void solve() {
	std::string s;
	std::cin >> s;
	s = s.substr(4);
	int l = s.size();
	int ans = 0;
	for (int i = 0; i < l; i++) {
		ans = ans * 10 + s[i] - '0';
	}
	int t = 0;
	int tt = 10;
	for (int i = 1; i < l; i++) {
		t += tt;
		tt *= 10;
	}
	while (t + 1989 > ans) {
		ans += tt;
	}
	std::cout << ans << endl;
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
