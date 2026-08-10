#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> v1(n), v2(n);
		for (auto &x: v1) cin >> x;
		for (auto &x: v2) cin >> x;

		long long ans = 0;

		{
			map<int, int> cnt;
			for (int i = 0; i < n; i ++) {
				ans += cnt[v1[i] - v2[i]];
				cnt[v1[i] - v2[i]] ++;
			}
		}

		{
			map<int, int> cnt;
			for (int i = 0; i < n; i ++) {
				ans += cnt[v1[i] + v2[i]];
				cnt[v1[i] + v2[i]] ++;
			}
		}

		{
			map<pair<int, int>, int> cnt;
			for (int i = 0; i < n; i ++) {
				ans -= cnt[{v1[i], v2[i]}];
				cnt[{v1[i], v2[i]}] ++;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}