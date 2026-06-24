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

	int M = 1 << 20;

	vector<int> is_prime(M, 1);
	is_prime[0] = 0, is_prime[1] = 0;

	for (int i = 2; i < M; i ++) {
		if (is_prime[i]) {
			for (int j = i * 2; j < M; j += i) {
				is_prime[j] = 0;
			}
		}
	}

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		map<vector<int>, long long> dp;
		dp[vector<int>()] = 0;

		while (n --) {
			int x;
			cin >> x;

			map<vector<int>, long long> ndp = dp;

			for (auto [nums, val]: dp) {
				int k = nums.size();

				for (int i = 0; i < 1 << k; i ++) {
					vector<int> tmp;

					for (int j = 0; j < k; j ++) {
						if (i >> j & 1) {
							tmp.emplace_back(nums[j]);
						}
					}

					tmp.emplace_back(x);

					bool flg = true;
					for (int a = 0; a < tmp.size(); a ++) {
						for (int b = 0; b < a; b ++) {
							if (!is_prime[tmp[a] ^ tmp[b]]) {
								flg = false;
							}
						}
					}

					if (flg) {
						sort(tmp.begin(), tmp.end());
						ndp[tmp] = max(ndp[tmp], val);
					}
				}
			}

			for (auto &[k, val]: ndp) {
				for (auto &v: k) {
					val += v;
				}
			}

			dp = ndp;
		}

		long long ans = 0;
		for (auto &[x, y]: dp) ans = max(ans, y);

		cout << ans << '\n';
	}

	return 0;
}