#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, a, b;
	cin >> n >> a >> b;

	int k1 = n / 2, k2 = n - k1;
	vector<int> v1(k1), v2(k2);

	for (int i = 0; i < k1; i ++) {
		int m, t;
		cin >> m >> t;
		m *= b;
		t *= b;
		v1[i] = m - t / b * a;
	}

	for (int i = 0; i < k2; i ++) {
		int m, t;
		cin >> m >> t;
		m *= b;
		t *= b;
		v2[i] = m - t / b * a;
	}

	map<long long, int> mp;

	auto dfs1 = [&] (auto &self, int idx, long long val) -> void {
		if (idx == k1) {
			mp[val] ++;
			return ;
		}
		self(self, idx + 1, val + v1[idx]);
		self(self, idx + 1, val);
	};

	dfs1(dfs1, 0, 0);

	long long ans = 0;

	auto dfs2 = [&] (auto &self, int idx, long long val) -> void {
		if (idx == k2) {
			auto pt = mp.find(-val);
			if (pt != mp.end()) ans += pt->second;
			return ;
		}
		self(self, idx + 1, val + v2[idx]);
		self(self, idx + 1, val);
	};

	dfs2(dfs2, 0, 0);

	cout << ans - 1;

	return 0;
}