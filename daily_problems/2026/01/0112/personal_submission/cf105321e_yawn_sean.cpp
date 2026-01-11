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

	int n, p;
	cin >> n >> p;

	vector<array<int, 3>> weapons(n);
	for (auto &[a, b, c]: weapons) cin >> a >> b >> c;

	sort(weapons.begin(), weapons.end(), [&] (array<int, 3> x, array<int, 3> y) {
		return 1ll * x[0] * y[1] + x[1] < 1ll * y[0] * x[1] + y[1];
	});

	vector<long long> dp(p + 1, 0);

	for (auto &[a, b, c]: weapons) {
		for (int i = b; i <= p; i ++) {
			dp[(i - b) / a] = max(dp[(i - b) / a], dp[i] + c);
		}
	}

	cout << *max_element(dp.begin(), dp.end());

	return 0;
}