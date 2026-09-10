#include <bits/stdc++.h>
// #include "atcoder/all"
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx2,tune=native")

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, mod = 1e9 + 7;
	cin >> n;

	vector<vector<int>> combs(n + 1, vector<int>(n + 1, 0));

	for (int i = 0; i <= n; i ++) {
		combs[i][0] = 1, combs[i][i] = 1;
		for (int j = 1; j < i; j ++) {
			combs[i][j] = (combs[i - 1][j] + combs[i - 1][j - 1]) % mod;
		}
	}

	vector<vector<int>> dp1(n + 1, vector<int>(n + 1, 0));
	vector<vector<int>> dp2(n + 1, vector<int>(n + 1, 0));

	dp1[0][0] = 1, dp2[0][0] = 1;

	for (int i = 0; i <= n; i ++) {
		for (int j = 0; j <= n; j ++) {
			for (int k = i + 1; k <= n; k ++) {
				dp2[k][j] = (dp2[k][j] + 1ll * dp1[i][j] * combs[k][i]) % mod;
			}
			for (int k = j + 1; k <= n; k ++) {
				dp1[i][k] = (dp1[i][k] + 1ll * dp2[i][j] * combs[k][j]) % mod;
			}
		}
	}

	cout << (dp1[n][n] + dp2[n][n]) % mod;

	return 0;
}