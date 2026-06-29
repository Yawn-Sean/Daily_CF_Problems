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

	int M = 1e6;

	vector<int> pr(M + 1), mu(M + 1, 0);
	iota(pr.begin(), pr.end(), 0);
	mu[1] = 1;

	for (int i = 2; i <= M; i ++) {
		if (pr[i] == i) {
			for (int j = M / i * i; j >= i; j -= i) {
				pr[j] = i;
				mu[j] = -mu[j / i];
			}
		}
	}

	auto factors = [&] (int x) -> vector<int> {
		vector<int> res = {1};
		while (x > 1) {
			int p = pr[x], c = 0;
			while (x % p == 0) x /= p, c ++;
			int l = res.size();
			for (int i = 0; i < l * c; i ++) res.emplace_back(res.end()[-l] * p);
		}
		return res;
	};

	vector<int> cnt(M + 1, 0);

	int t;
	cin >> t;

	while (t --) {
		int n, q;
		cin >> n >> q;

		vector<int> nums(n);
		for (auto &v: nums) cin >> v;

		for (auto &v: nums) for (auto &x: factors(v)) cnt[x] ++;

		while (q --) {
			int ty, idx, val;
			cin >> ty >> idx >> val; idx --;

			if (ty == 1) {
				if (nums[idx] % val) cout << 0 << '\n';
				else {
					int ans = 0;
					for (auto &v: factors(nums[idx] / val))
						ans += mu[v] * cnt[v * val];
					if (nums[idx] == val) ans --;
					cout << ans << '\n';
				}
			}
			else {
				for (auto &v: factors(nums[idx])) cnt[v] --;
				nums[idx] = val;
				for (auto &v: factors(nums[idx])) cnt[v] ++;
			}
		}

		for (auto &v: nums) for (auto &x: factors(v)) cnt[x] --;
	}

	return 0;
}