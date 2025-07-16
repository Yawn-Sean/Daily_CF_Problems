#include<bits/stdc++.h>
#define endl '\n'
using i64 = long long;
using u64 = unsigned long long;
using d64 = double;
using ld64 = long double;

void solve() {
	std::string s;
	std::cin >> s;
	s = " " + s;
	int n = s.size();
	std::vector<int> a(n), b(n);
	std::vector<int> cnt(n);
	for (int i = 1; i < n; i++) {
		cnt[i] = cnt[i - 1];
		if (s[i] == '[') {
			cnt[i]++;
		}
	}
	std::vector<char> cur;
	std::vector<int> k;
	int st = 0;
	int l = 0;
	int r = 0;
	int maxn = 0;
	int val = 0;
	int now = 0;
	std::vector<std::pair<int, int>> v;
	for (int i = 1; i < n; i++) {
		if (s[i] == '(' || s[i] == '[') {
			cur.push_back(s[i]);
			k.push_back(i);
		}
		else {
			if (s[i] == ')') {
				if (cur.empty()) {
					st = i;
				}
				else if (cur.back() == '(') {
					cur.pop_back();
					k.pop_back();
				}
				else {
					st = i;
					cur.clear();
					k.clear();
				}
			}
			else {
				if (cur.empty()) {
					st = i;
				}
				else if (cur.back() == '[') {
					cur.pop_back();
					k.pop_back();
				}
				else {
					st = i;
					cur.clear();
					k.clear();
				}
			}
		}

		if (cur.empty()) {
			if (st != i) {
				v.push_back({st, i});
			}
			st = i;
		}
		else {
			// std::cerr << k.back() << " " << i << endl;
			int now = k.back();
			// std::cout << cnt[now] << " " << cnt[i] << endl;
			if (cnt[i] - cnt[now] > maxn) {
				l = now;
				r = i;
				maxn = cnt[r] - cnt[l];
			}
		}
	}
	if (v.size() == 0) {
		if (maxn == 0) {
			std::cout << 0 << endl;
			std::cout << endl;
		}
		else {
			std::cout << maxn << endl;
			for (int i = l + 1; i <= r; i++) {
				std::cout << s[i];
			}
		}
		return ;
	}

	if (cnt[v[0].second] - cnt[v[0].first] > maxn) {
		l = v[0].first;
		r = v[0].second;
		maxn = cnt[r] - cnt[l];
	}
	int m = v.size();
	for (int i = 1; i < m; i++) {
		if (v[i].first == v[i - 1].second) {
			v[i].first = v[i - 1].first;
		}
		if (cnt[v[i].second] - cnt[v[i].first] > maxn) {
			maxn = cnt[v[i].second] - cnt[v[i].first];
			l = v[i].first;
			r = v[i].second;
		}
	}
	if (maxn == 0) {
		std::cout << 0 << endl;
		std::cout << endl;
	}
	else {
		std::cout << maxn << endl;
		for (int i = l + 1; i <= r; i++) {
			std::cout << s[i];
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
