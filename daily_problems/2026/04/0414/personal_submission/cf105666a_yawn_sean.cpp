#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's unordered_set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	vector<long long> possible_vals = {1};
	long long bound; cin >> bound;

	for (auto &x: {2, 3, 5, 7}) {
		int k = possible_vals.size();
		for (int i = 0; i < k; i ++) {
			long long cur = possible_vals[i];
			while (cur <= bound / x) {
				cur *= x;
				possible_vals.emplace_back(cur);
			}
		}
	}

	int k = possible_vals.size();

	unordered_map<long long, int> mp;
	for (int i = 0; i < k; i ++) mp[possible_vals[i]] = i;

	int ans = 0;

	vector<int> dp(k, 0);
	dp[0] = 1;

	for (int i = 0; i < k; i ++) {
		ans += dp[i];
		if (dp[i]) {
			for (int x = 2; x <= 9; x ++) {
				if (possible_vals[i] <= bound / x) {
					long long val = possible_vals[i] * x;
					bool flg = false;

					while (val) {
						if (val % 10 == x) flg = true;
						val /= 10;
					}

					if (flg) dp[mp[possible_vals[i] * x]] = 1;
				}
			}
		}
	}

	cout << ans;

	return 0;
}