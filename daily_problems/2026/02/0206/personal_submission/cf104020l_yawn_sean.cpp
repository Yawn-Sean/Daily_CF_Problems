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

	vector<array<int, 3>> pts(n);
	for (auto &[x, y, z]: pts) cin >> x >> y >> z;

	sort(pts.begin(), pts.end());

	long long ans = 4e18;

	for (int i = 0; i < n; i ++) {
		auto [x1, y1, z1] = pts[i];

		for (int j = max(0, i - 100); j < i; j ++) {
			auto [x2, y2, z2] = pts[j];

			ans = min(ans, 1ll * (x2 - x1) * (x2 - x1) + 1ll * (y2 - y1) * (y2 - y1) + 1ll * (z2 - z1) * (z2 - z1));
		}
	}

	cout << fixed << setprecision(10) << sqrtl(ans);

	return 0;
}