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

		long long ans = 0;

		for (int i = 1; i <= n; i ++) {
			int m_bound = min(i - 1, m);

			int x = i;
			vector<int> vals;

			while (x) {
				int v = x & -x;
				vals.emplace_back(v);
				x -= v;
			}

			if (m_bound < vals.back()) continue;

			int cur = vals.back();
			ans ++;

			for (int j = (int)vals.size() - 2; j >= 0; j --) {
				if (cur + vals[j] <= m_bound) {
					cur += vals[j];
					ans += 1 << j;
				}
			}
		}

		swap(n, m);

		for (int i = 1; i <= n; i ++) {
			int m_bound = min(i - 1, m);

			int x = i;
			vector<int> vals;

			while (x) {
				int v = x & -x;
				vals.emplace_back(v);
				x -= v;
			}

			if (m_bound < vals.back()) continue;

			int cur = vals.back();
			ans ++;

			for (int j = (int)vals.size() - 2; j >= 0; j --) {
				if (cur + vals[j] <= m_bound) {
					cur += vals[j];
					ans += 1 << j;
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}