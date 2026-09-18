#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

__int128_t gcd128(__int128_t a, __int128_t b) {
    while (b) { a %= b; swap(a, b); }
    return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<pair<int, int>> pts(n);
		for (auto &[x, y]: pts) cin >> x >> y;

		int ans = 2;

		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < i; j ++) {
				auto [x1, y1] = pts[i];
				auto [x2, y2] = pts[j];

				long long sq = 1ll * (x1 - x2) * (x1 - x2) + 1ll * (y1 - y2) * (y1 - y2);

				map<pair<__int128_t, __int128_t>, int> mp;

				for (int k = 0; k < j; k ++) {
					auto [x3, y3] = pts[k];

					if (1ll * (x1 - x2) * (y1 - y3) == 1ll * (x1 - x3) * (y1 - y2))
						continue;

					int dx1 = x1 - x3, dy1 = y1 - y3;
					int dx2 = x2 - x3, dy2 = y2 - y3;

					__int128_t a = (1ll * dx1 * dx1 + 1ll * dy1 * dy1) + (1ll * dx2 * dx2 + 1ll * dy2 * dy2) - sq;
					__int128_t b = (__int128_t)1 * (1ll * dx1 * dx1 + 1ll * dy1 * dy1) * (1ll * dx2 * dx2 + 1ll * dy2 * dy2);

					bool flg = (a < 0) ^ (1ll * (x1 - x2) * (y1 - y3) < 1ll * (x1 - x3) * (y1 - y2));

					a = a * a;
					auto g = gcd128(a, b);
					a /= g;
					b /= g;

					if (flg) a = -a;

					mp[{a, b}] ++;
					ans = max(ans, mp[{a, b}] + 2);
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}