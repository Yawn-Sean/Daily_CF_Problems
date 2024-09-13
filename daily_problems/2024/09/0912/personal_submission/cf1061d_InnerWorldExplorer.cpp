#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
using namespace std;

using i64 = long long;

const int MOD = (int)1E9 + 7;

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n, x, y;
	cin >> n >> x >> y;
	vector<pair<int, int>> lr(n);
	int l, r;
	for (int i = 0; i < n; i ++) {
		cin >> l >> r;
		lr[i] = {l, r};
	}
	sort(lr.begin(), lr.end());
	multiset<pair<int, int>> s;
	vector<vector<pair<int, int>>> tvs;

	int j = 0;
	auto f1 = [&](int i) {
		tvs.push_back(vector<pair<int, int>> {{lr[i].first, lr[i].second}});
		s.insert({lr[i].second, j ++});
	};
	auto f2 = [&](int i, auto & it) {
		tvs[it->second].push_back({lr[i].first, lr[i].second});
		s.insert({lr[i].second, it->second});
		s.erase(it);
	};
	for (int i = 0; i < n; i ++) {
		auto it = s.lower_bound({lr[i].first, 0});
		if (it == s.begin()) {
			f1(i);
		} else {
			it --;
			if (1LL * y * (tvs[it->second].back().second - lr[i].first) + x < 0) {
				f1(i);
			} else {
				f2(i, it);
			}
		}
	}
	i64 ans = 0;
	for (auto &tv : tvs) {
		auto b = tv.back();
		auto f = tv.front();
		i64 tmp = (1LL * y * (b.second - f.first) % MOD + x % MOD) % MOD;
		ans = (ans % MOD + tmp) % MOD;
	}
	cout << ans % MOD << endl;
	return 0;
}
