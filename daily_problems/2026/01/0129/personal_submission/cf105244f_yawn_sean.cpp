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

	int M = 1e3;
	vector<int> ops(M + 1, M);
	ops[0] = ops[1] = 0;

	for (int i = 1; i <= M; i ++) {
		for (int j = 1; j <= i; j ++) {
			int ni = i + i / j;
			if (ni <= M) {
				ops[ni] = min(ops[ni], ops[i] + 1);
			}
		}
	}

	int n, k;
	cin >> n >> k;

	vector<int> target(n), gains(n);
	for (auto &v: target) cin >> v;
	for (auto &v: gains) cin >> v;

	vector<int> dp(12001, 0);
	for (int i = 0; i < n; i ++) {
		int val = ops[target[i]], gain = gains[i];
		for (int j = 12000; j >= val; j --) {
			dp[j] = max(dp[j], dp[j - val] + gain);
		}
	}

	int ans = 0;
	for (int i = 0; i <= 12000 && i <= k; i ++)
		ans = max(ans, dp[i]);
	cout << ans << '\n';

	return 0;
}