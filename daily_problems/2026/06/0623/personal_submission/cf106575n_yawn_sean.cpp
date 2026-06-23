#include <bits/stdc++.h>
// #pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

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
		int n, ca, cb;
		cin >> n >> ca >> cb;

		vector<int> p1(n), p2(n);

		for (int i = 0; i < n; i ++) {
			int x; cin >> x;
			p1[(x - 1) / 2] = i;
		}

		for (int i = 0; i < n; i ++) {
			int x; cin >> x;
			p2[(x - 1) / 2] = i;
		}

		long long ans = 1e18;
		int cur = n;

		for (int i = 0; i < n; i ++) {
			cur = min(cur, p1[i]);
			ans = min(ans, 1ll * cur * ca + 1ll * p2[i] * cb);
		}

		cout << ans << '\n';
	}

	return 0;
}