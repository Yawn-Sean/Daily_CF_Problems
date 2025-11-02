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

	int t, mod = 1e9 + 7;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> xs(n * 2), ys(n * 2);
		for (int i = 0; i < 2 * n; i ++)
			cin >> xs[i] >> ys[i];

		vector<int> vxs = xs, vys = ys;
		sort(vxs.begin(), vxs.end());
		sort(vys.begin(), vys.end());

		if (vxs[n - 1] == vxs[n] || vys[n - 1] == vys[n]) cout << 0 << '\n';
		else {
			int v1 = 1, v2 = 1, ans = 1;
			for (int i = 0; i < 2 * n; i ++) {
				if (xs[i] < vxs[n]) {
					if (ys[i] < vys[n]) ans = 1ll * ans * (v1 ++) % mod;
					else ans = 1ll * ans * (v2 ++) % mod;
				}
			}
			cout << ans << '\n';
		}
	}

	return 0;
}