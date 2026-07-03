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

	int n, m;
	cin >> n >> m;

	vector<vector<int>> grid(n, vector<int>(m));
	for (auto &x: grid) for (auto &y: x) cin >> y;

	vector<vector<int>> cnt(n, vector<int>(m, 0));

	for (int i = 0; i < n; i ++) {
		map<int, int> d;
		for (int j = m - 1; j >= 0; j --) {
			cnt[i][j] = d[grid[i][j] + j];
			d[grid[i][j] + j] ++;
		}
	}

	long long ans = 0;

	for (int j = 0; j < m; j ++) {
		map<int, int> d;
		for (int i = n - 1; i >= 0; i --) {
			ans += cnt[i][j] * d[grid[i][j] + i];
			d[grid[i][j] + i] ++;
		}
	}

	cout << ans;

	return 0;
}