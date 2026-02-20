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

	int n, b;
	cin >> n >> b;

	vector<int> xs(n), ys(n);
	for (auto &x: xs) cin >> x;
	for (auto &y: ys) cin >> y;

	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&] (int i, int j) {
		return ys[i] > ys[j];
	});

	long long inf = 2e9;
	vector<long long> dp(n + 1, inf);

	dp[0] = 0;

	for (int i = 0; i < n; i ++) {
		int idx = order[i];
		int x = xs[idx], y = ys[idx];

		for (int j = i; j >= 0; j --) {
			dp[j + 1] = min(dp[j + 1], dp[j] + x + 1ll * j * y);
		}
	}

	for (int i = n; i >= 0; i --) {
		if (dp[i] <= b) {
			cout << i << ' ' << dp[i] << '\n';
			break;
		}
	}

	return 0;
}