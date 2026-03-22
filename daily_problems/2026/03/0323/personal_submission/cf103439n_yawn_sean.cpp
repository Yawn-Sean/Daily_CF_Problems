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

	int n;
	cin >> n;

	vector<pair<int, int>> pairs(2 * n);
	for (auto &[x, y]: pairs) cin >> x >> y;

	sort(pairs.begin(), pairs.end(), [&] (pair<int, int> &x, pair<int, int> &y) {
		return x.first + x.second < y.first + y.second;
	});

	long long ans = 0;

	for (int i = 0; i < n; i ++) {
		auto [x1, y1] = pairs[i];
		auto [x2, y2] = pairs[2 * n - 1 - i];
		ans += max(x2, y2) - min(x1, y1);
	}

	cout << ans << '\n';

	return 0;
}