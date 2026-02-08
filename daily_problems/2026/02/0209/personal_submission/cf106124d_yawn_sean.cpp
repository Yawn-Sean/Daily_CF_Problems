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

	vector<pair<int, int>> pts(n);
	for (auto &[x, y]: pts) cin >> x >> y;

	auto dis = [&] (int x, int y) -> long long {
		auto [x1, y1] = pts[x];
		auto [x2, y2] = pts[y];
		return 1ll * (x1 - x2) * (x1 - x2) + 1ll * (y1 - y2) * (y1 - y2);
	};

	int idx = 0;
	for (int i = 0; i < n; i ++) {
		if (dis(0, i) > dis(0, idx)) {
			idx = i;
		}
	}

	vector<int> order(n);
	iota(order.begin(), order.end(), 0);
	sort(order.begin(), order.end(), [&] (int i, int j) {return dis(idx, i) < dis(idx, j);});

	long double ans = 0;
	for (int i = 1; i < n; i ++)
		ans += sqrtl(dis(order[i - 1], order[i]));

	cout << fixed << setprecision(15) << ans;

	return 0;
}