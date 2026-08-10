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
		int n, m;
		cin >> n >> m;

		vector<string> grid(n);
		for (auto &x: grid) cin >> x;

		vector<int> c1(n, 0), c2(m, 0);

		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				c1[i] += grid[i][j] - '0';
				c2[j] += grid[i][j] - '0';
			}
		}

		long long cur = 0;
		vector<int> adds1(n, 0), adds2(m, 0);

		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				if (grid[i][j] == '1') {
					cur += (c1[i] - 1) * (c2[j] - 1);
					adds1[i] += c2[j] - 1;
					adds2[j] += c1[i] - 1;
				}
			}
		}

		long long ans = -1, cnt = 0;

		for (int i = 0; i < n; i ++) {
			for (int j = 0; j < m; j ++) {
				if (grid[i][j] == '0') {
					long long ncur = cur + c1[i] * c2[j] + adds1[i] + adds2[j];

					if (ncur > ans) ans = ncur, cnt = 1;
					else if (ncur == ans) cnt ++;
				}
			}
		}

		cout << ans << ' ' << cnt << '\n';
	}

	return 0;
}