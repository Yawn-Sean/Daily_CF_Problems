#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;

void solve() {
	std::string s, t;
	std::cin >> s >> t;
	sort(s.begin(), s.end());
	sort(t.begin(), t.end(), std::greater<>());
	int s1 = 0;
	int t1 = 0;
	int n = s.size();
	std::vector<char> ans(n);
	int l = 0;
	int r = n - 1;
	int cnt = (n + 1) / 2 - 1;
	int cnt2 = (n) / 2 - 1;
	for (int i = 0; i < n; i++) {
		if (i & 1) {
			if (t[t1] <= s[s1]) {
				ans[r--] = t[cnt2--];
			}
			else {
				ans[l++] = t[t1++];
			}
		}
		else {
			if (s[s1] >= t[t1]) {
				ans[r--] = s[cnt--];
			}
			else {
				ans[l++] = s[s1++];
			}
		}
	}
	for (auto x : ans) {
		std::cout << x;
	}
}
signed main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	std::cout.tie(0);
	solve();
	return 0;
}
