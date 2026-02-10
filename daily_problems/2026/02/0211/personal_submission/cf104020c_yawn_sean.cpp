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

	int c, t, r;
	double p;
	cin >> c >> t >> r >> p;

	vector<double> time(c + 1, 0);
	for (int i = 0; i < c; i ++)
		time[i + 1] = (time[i] + 1 + p * r) / (1 - p);

	vector<double> dp(c + 1, 1e18);
	dp[0] = 0;
	for (int i = 1; i <= c; i ++) {
		for (int j = 0; j <= i; j ++) {
			dp[i] = min(dp[i], dp[i - j] + time[j] + t);
		}
	}

	cout << fixed << setprecision(10) << dp[c];

	return 0;
}