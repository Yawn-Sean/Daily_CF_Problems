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

	int n;
	cin >> n;

	vector<int> nums(n);
	for (auto &v: nums) cin >> v;
	sort(nums.begin(), nums.end());

	vector<int> cnt(n, 0);
	for (auto &x: nums)
		cnt[lower_bound(nums.begin(), nums.end(), x) - nums.begin()] ++;

	vector<vector<int>> vals(n);
	int c = 0;

	for (int i = 0; i < n; i ++) {
		if (cnt[i]) {
			vals[i].emplace_back(nums[i]);
			cnt[i] --;
			c ++;
		}
	}

	if (2 * c - 1 != n) cout << -1;
	else {
		int cur = (n + 1) / 2;
		while (cur > 1) {
			vector<int> p1, p2;
			for (int i = 0; i < n; i ++) {
				if (vals[i].size()) {
					if (cnt[i]) p1.emplace_back(i);
					else p2.emplace_back(i);
				}
			}

			if (p1.size() != p2.size()) return cout << -1, 0;

			for (int i = 0; i < p1.size(); i ++) {
				int x = p1[i], y = p2[i];
				if (x > y) return cout << -1, 0;
				for (auto &v: vals[y]) vals[x].emplace_back(v);
				vals[y].clear();
				cnt[x] --;
			}

			cur = (cur + 1) / 2;
		}

		for (auto &v: vals[0]) cout << v << ' ';
	}

	return 0;
}