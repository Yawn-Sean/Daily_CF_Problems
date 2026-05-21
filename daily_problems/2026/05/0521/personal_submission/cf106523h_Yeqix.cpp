#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

constexpr int N = 1e5;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<int> mn(N + 1);
	iota(mn.begin() + 1, mn.end(), 1);
	for (int i = 2; i * i <= N; i++) {
		if (mn[i] != i) {
			continue;
		}
		for (int j = i * i; j <= N; j += i) {
			if (mn[j] == j) {
				mn[j] = i;
			}
		}
	}

	set<i64> st;
	map<i64, i64> mp;

	auto get = [&](int x)->vector<array<int, 2>> {
		vector<array<int, 2>> f;
		while (x > 1) {
			int now = mn[x];
			int cnt = 0;
			while (x % now == 0) {
				cnt++;
				x /= now;
			}
			f.push_back({now, cnt});
		}
		return f;
	};

	int q;
	cin >> q;
	while (q--) {
		int op, x;
		cin >> op >> x;
		if (op == 2) {
			auto it = mp.begin();
			while (it != mp.end()) {
				it->second *= x;
				if (it->second >= N) {
					st.insert(it->first);
					it = mp.erase(it);
				} else {
					it++;
				}
			}
			continue;
		}

		auto f = get(x);
		if (op == 1) {
			for (const auto& [l, r] : f) {
				if (st.count(l)) {
					continue;
				}
				mp[l] += r;
				if (mp[l] >= N) {
					mp.erase(l);
					st.insert(l);
				}
			}
		} else {
			bool ans = 1;
			for (const auto&[l, r] : f) {
				if (!(st.count(l) || mp.count(l) && mp[l] >= r)) {
					ans = 0;
					break;
				}
			}
			if (ans) {
				cout << "Yes\n";
			} else {
				cout << "No\n";
			}
		}
	}
	return 0;
}