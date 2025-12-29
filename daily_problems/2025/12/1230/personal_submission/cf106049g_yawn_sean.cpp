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

	int t, mod = 998244353;
	cin >> t;

	while (t --) {
		long long n, l, r;
		cin >> n >> l >> r;

		long long block_cnt = n / l;
		if (block_cnt * r < n) cout << "-1\n";
		else {
			vector<int> ans;
			for (int i = 1; i <= block_cnt; i ++) {
				long long v = max(l, n - (block_cnt - i) * r);
				n -= v;
				ans.emplace_back(v);
			}

			int res = 1;
			for (int i = 1; i <= ans[0]; i ++) res = 1ll * res * i % mod;

			cout << block_cnt << ' ' << res << '\n';
			int cur = 1;

			for (auto &x: ans) {
				cout << cur << ' ' << cur + x - 1 << '\n';
				cur += x;
			}
		}
	}

	return 0;
}