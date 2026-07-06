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

	int t, mod = 1e9 + 7;
	cin >> t;

	while (t --) {
		int n, m;
		cin >> n >> m;

		vector<int> tmp1(m + 1), tmp2(m + 1);
		while (n --) {
			int l, r;
			cin >> l >> r;
			tmp1[l] = (tmp1[l] + m + 1 - r) % mod;
			tmp2[r] = (tmp2[r] + l) % mod;
		}

		int ans = 0, total = 0;

		for (int i = m; i >= 1; i --) {
			ans = (ans + 1ll * total * tmp2[i]) % mod;
			total = (total + tmp1[i]) % mod;
		}

		cout << ans << '\n';
	}

	return 0;
}