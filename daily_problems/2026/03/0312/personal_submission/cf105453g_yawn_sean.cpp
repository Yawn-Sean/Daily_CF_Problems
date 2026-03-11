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

	int n, T;
	cin >> n >> T;

	vector<int> ts, bs;

	int ans = 0;
	for (int i = 0; i < n; i ++) {
		int t, b, c;
		cin >> t >> b >> c;
		ans += c;
		ts.emplace_back(t);
		bs.emplace_back(b - c);
	}

	vector<int> dp(n + 1, 0);
	int pt = 0;

	for (int i = 0; i < n; i ++) {
		while (ts[i] - ts[pt] >= T && pt + 1 <= i) pt ++;
		dp[i + 1] = max(dp[i], dp[pt] + bs[i]);
	}

	cout << dp[n] + ans;

	return 0;
}