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

	int n, M = 1e6;
	cin >> n;

	vector<int> xs(n), ys(n), vs(n);
	for (int i = 0; i < n; i ++)
		cin >> xs[i] >> ys[i] >> vs[i];

	auto solve = [&] () -> int {
		vector<int> cnt(M + 1, 0);

		for (int i = 0; i < n; i ++)
			cnt[ys[i]] += vs[i];
		
		vector<int> order(M + 1);
		iota(order.begin(), order.end(), 0);
		sort(order.begin(), order.end(), [&] (int i, int j) {return cnt[i] > cnt[j];});

		int ans = cnt[order[0]] + cnt[order[1]] + cnt[order[2]];

		map<int, vector<int>> mp;
		for (int i = 0; i < n; i ++)
			mp[xs[i]].emplace_back(i);
		
		for (auto &[k, v]: mp) {
			int cur = 0;
			for (auto &idx: v) {
				cur += vs[idx];
				cnt[ys[idx]] -= vs[idx];
			}

			int v1 = 0, v2 = 0;
			for (int i = 0; i < v.size() + 2; i ++) {
				int val = cnt[order[i]];
				if (val > v1) swap(v1, v2), v1 = val;
				else if (val > v2) v2 = val;
			}

			ans = max(ans, cur + v1 + v2);

			for (auto &idx: v)
				cnt[ys[idx]] += vs[idx];
		}
		
		return ans;
	};

	int res = solve();

	for (int i = 0; i < n; i ++)
		swap(xs[i], ys[i]);
	
	res = max(res, solve());
	cout << res;

    return 0;
}