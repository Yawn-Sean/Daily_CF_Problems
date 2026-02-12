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

int dp[4][505][505];
int ndp[4][505][505];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k, mod = 1e9 + 7;
	cin >> n >> k;

	for (int i = 0; i < n; i ++) dp[1][i][0] = 1;

	auto add = [&] (int &x, int y) -> void {
		x += y;
		if (x >= mod) x -= mod;
	};

	auto minus = [&] (int &x, int y) -> void {
		x -= y;
		if (x < 0) x += mod;
	};

	for (int i = 0; i < n - 1;) {
		for (int x = 1; x <= 3; x ++) {
			for (int y = 0; y < n - i; y ++) {
				for (int z = 0; z <= max(i - 2, 0); z ++) {
					add(ndp[1][0][z], dp[x][y][z]);
					minus(ndp[1][y][z], dp[x][y][z]);

					if (x < 3) {
						add(ndp[x + 1][y][z], dp[x][y][z]);
						minus(ndp[x + 1][n - 1 - i][z], dp[x][y][z]);
					}
					else {
						add(ndp[3][y][z + 1], dp[x][y][z]);
						minus(ndp[3][n - 1 - i][z + 1], dp[x][y][z]);
					}
				}
			}
		}

		i ++;
		for (int x = 1; x <= 3; x ++) {
			for (int y = 0; y < n - i; y ++) {
				for (int z = 0; z <= max(i - 2, 0); z ++) {
					add(ndp[x][y + 1][z], ndp[x][y][z]);
					dp[x][y][z] = ndp[x][y][z];
					ndp[x][y][z] = 0;
				}
			}
		}
	}

	int ans = 0;
	for (int x = 1; x <= 3; x ++) add(ans, dp[x][0][k]);

	cout << ans;

	return 0;
}