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

	int t;
	cin >> t;

	while (t --) {
		int n, m;
		cin >> n >> m;

		vector<int> cnt(m, 0);

		for (int i = 0; i < n; i ++) {
			string s;
			cin >> s;

			if (s[m - 1] == '1') cnt[m - 1] ++;

			for (int j = 0; j < m - 1; j ++) {
				if (s[j] != s[j + 1]) {
					cnt[j] ++;
				}
			}
		}

		int ans = 0;
		for (auto &x: cnt) ans += min(x, n - x);
		cout << ans << '\n';
	}

	return 0;
}