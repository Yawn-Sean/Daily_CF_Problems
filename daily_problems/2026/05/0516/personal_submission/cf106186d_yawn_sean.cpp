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

	int M = 1e5 + 5;
	vector<int> pr(M, 1);
	pr[0] = 0, pr[1] = 0;

	for (int i = 2; i < M; i ++) {
		if (pr[i]) {
			for (int j = 2 * i; j < M; j += i) {
				pr[j] = 0;
			}
		}
	}

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> c1(n + 1, 0), c2(n + 1, 0);

		for (int i = 0; i < n; i ++) {
			int x; cin >> x;
			c1[x] ++;
		}

		for (int i = 0; i < n; i ++) {
			int x; cin >> x;
			c2[x] ++;
		}

		for (int i = 1; i <= n; i ++) {
			for (int j = 2 * i; j <= n; j += i) {
				c1[i] += c1[j];
				c2[i] += c2[j];
			}
		}

		vector<long long> cnt(n + 1, 0);
		for (int i = 0; i <= n; i ++) {
			cnt[i] = 1ll * c1[i] * c2[i];
		}

		for (int i = n; i >= 1; i --) {
			for (int j = 2 * i; j <= n; j += i) {
				cnt[i] -= cnt[j];
			}
		}

		long long ans = 0;
		for (int i = 0; i <= n; i ++) {
			if (pr[i]) {
				ans += cnt[i];
			}
		}

		cout << ans << '\n';
	}

	return 0;
}