#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, h;
	cin >> n >> h;

	if (!n) return cout << h, 0;

	vector<array<int, 3>> circles(n);

	for (auto &[x, y, r]: circles) cin >> x >> y >> r;

	vector<long double> dis(n);

	for (int i = 0; i < n; i ++) {
		auto [x, y, r] = circles[i];
		dis[i] = max(0, y - r);
	}

	vector<bool> vis(n, false);

	for (int i = 0; i < n; i ++) {
		int chosen = -1;
		for (int j = 0; j < n; j ++) {
			if (!vis[j] && (chosen == -1 || dis[j] < dis[chosen])) {
				chosen = j;
			}
		}

		vis[chosen] = 1;

		for (int j = 0; j < n; j ++) {
			auto [x1, y1, r1] = circles[chosen];
			auto [x2, y2, r2] = circles[j];
			dis[j] = min(dis[j], dis[chosen] + max((long double)0, hypotl(x1 - x2, y1 - y2) - r1 - r2));
		}
	}

	long double ans = h;

	for (int i = 0; i < n; i ++) {
		auto [x, y, r] = circles[i];
		ans = min(ans, dis[i] + max(0, h - (y + r)));
	}

	cout << fixed << setprecision(15) << ans;

	return 0;
}