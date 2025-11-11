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

	int n;
	cin >> n;

	vector<string> grid(n);
	for (auto &s: grid) cin >> s;

	int ans = 0;
	vector<int> cnt(n, 0);

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j ++) {
			if (grid[i][j] == '1') {
				ans = 1;
				cnt[j] ++;
			}
		}
	}

	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < i; j ++) {
			int v = 0, w = 0;
			for (int k = 0; k < n; k ++) {
				if (grid[i][k] == '1' && grid[j][k] == '1') {
					v ++;
					w = max(w, cnt[k]);
				}
			}
			ans = max(ans, min(v, w));
		}
	}

	cout << ans;

	return 0;
}