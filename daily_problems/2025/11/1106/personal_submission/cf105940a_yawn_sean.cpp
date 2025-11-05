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

int dp[3][3][3][3], ndp[3][3][3][3], mod = 1e9 + 7;

void add(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	vector<int> method = {4, 3, 3};

	while (t --) {
		int n;
		cin >> n;

		for (int i = 1; i < 10; i ++) {
			vector<int> cur = {1, 0, 0};
			cur[i % 3] ++;
			dp[cur[0]][cur[1]][cur[2]][i % 3] ++;
		}

		for (int i = 1; i < n; i ++) {
			for (int x = 0; x < 3; x ++) {
				for (int y = 0; y < 3; y ++) {
					for (int z = 0; z < 3; z ++) {
						for (int cur_mod = 0; cur_mod < 3; cur_mod ++) {
							if (dp[x][y][z][cur_mod]) {
								vector<int> nstatus = {x, y, z};
								for (int choice = 0; choice < 3; choice ++) {
									int ncur_mod = (cur_mod + choice) % 3;
									nstatus[ncur_mod] = (nstatus[ncur_mod] + 1) % 3;
									add(ndp[nstatus[0]][nstatus[1]][nstatus[2]][ncur_mod], 1ll * dp[x][y][z][cur_mod] * method[choice] % mod);
									nstatus[ncur_mod] = (nstatus[ncur_mod] + 2) % 3;
								}
							}
						}
					}
				}
			}
			for (int x = 0; x < 3; x ++) {
				for (int y = 0; y < 3; y ++) {
					for (int z = 0; z < 3; z ++) {
						for (int v = 0; v < 3; v ++) {
							dp[x][y][z][v] = ndp[x][y][z][v];
							ndp[x][y][z][v] = 0;
						}
					}
				}
			}
		}

		int ans = 0;
		for (int x = 0; x < 3; x ++) {
			for (int y = 0; y < 3; y ++) {
				for (int z = 0; z < 3; z ++) {
					for (int v = 0; v < 3; v ++) {
						if ((x * (x - 1) / 2 + y * (y - 1) / 2 + z * (z - 1) / 2) % 3 == 0) add(ans, dp[x][y][z][v]);
						dp[x][y][z][v] = 0;
					}
				}
			}
		}

		cout << ans << '\n';
	}

	return 0;
}