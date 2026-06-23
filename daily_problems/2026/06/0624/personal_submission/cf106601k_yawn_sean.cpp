#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, q;
	cin >> n >> q;

	vector<int> pr(n + 1);
	iota(pr.begin(), pr.end(), 0);

	for (int i = 2; i <= n; i ++) {
		if (pr[i] == i) {
			for (int j = i; j <= n; j += i) {
				pr[j] = i;
			}
		}
	}

	int M = 1e6 + 5;
	vector<int> nums(n), cnt(M, 0), ans(M, 0);
	for (auto &x: nums) cin >> x, cnt[x] ++;

	for (auto &v: cnt) ans[v] ++;

	for (int i = 1; i <= n; i ++) {
		for (int j = i * 2; j <= n; j += i) {
			ans[i] += ans[j];
		}
	}

	auto factors = [&] (int x) -> vector<int> {
		if (!x) return vector<int>();

		vector<int> res = {1};

		while (x > 1) {
			int p = pr[x], c = 0;
			while (x % p == 0)
				x /= p, c ++;

			int l = res.size();
			for (int i = 0; i < c * l; i ++)
				res.emplace_back(res.end()[-l] * p);
		}

		return res;
	};

	while (q --) {
		int t;
		cin >> t;

		if (t == 1) {
			int idx, val;
			cin >> idx >> val, idx --;

			for (auto &x: factors(cnt[nums[idx]])) ans[x] --;
			cnt[nums[idx]] --;
			for (auto &x: factors(cnt[nums[idx]])) ans[x] ++;

			nums[idx] = val;

			for (auto &x: factors(cnt[nums[idx]])) ans[x] --;
			cnt[nums[idx]] ++;
			for (auto &x: factors(cnt[nums[idx]])) ans[x] ++;
		}
		else {
			int x;
			cin >> x;
			cout << ans[x] << '\n';
		}
	}

	return 0;
}