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

	int n;
	cin >> n;

	vector<vector<int>> grid(n, vector<int>(n));
	for (auto &x: grid) for (auto &y: x) cin >> y;

	vector<int> cur(n), vis(n, 0);
	for (int i = 0; i < n; i ++) cur[i] = grid[i][i];

	int ans = 0;

	for (int i = 0; i < n; i ++) {
		int chosen = -1;
		for (int j = 0; j < n; j ++) {
			if (!vis[j] && (chosen == -1 || cur[j] < cur[chosen])) {
				chosen = j;
			}
		}

		ans += cur[chosen];
		vis[chosen] = 1;

		for (int j = 0; j < n; j ++) {
			cur[j] = min(cur[j], grid[chosen][j]);
		}
	}

	cout << ans;

	return 0;
}