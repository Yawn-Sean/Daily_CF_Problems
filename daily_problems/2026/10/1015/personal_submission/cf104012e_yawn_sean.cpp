#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<string> grid(n);
	for (auto &s: grid) cin >> s;

	int ans = 1, mod = 998244353;

	for (int i = 0; i < n; i ++) {
		int dp0 = 1, dp1 = 0;

		for (int j = 0; j < n; j ++) {
			if (grid[i][j] == '.') {
				dp0 = (dp0 + dp1) % mod;
				dp1 = 0;
			}
			else if (grid[i][j] == '#') {
				if (j && grid[i][j - 1] == '#') continue;
				dp1 = dp0;
				dp0 = 0;
			}
			else {
				dp1 = (dp0 + dp1) % mod;
			}
		}

		ans = 1ll * ans * (dp0 + dp1) % mod;
	}

	for (int j = 0; j < n; j ++) {
		int dp0 = 1, dp1 = 0;

		for (int i = 0; i < n; i ++) {
			if (grid[i][j] == '.') {
				dp0 = (dp0 + dp1) % mod;
				dp1 = 0;
			}
			else if (grid[i][j] == '#') {
				if (i && grid[i - 1][j] == '#') continue;
				dp1 = dp0;
				dp0 = 0;
			}
			else {
				dp1 = (dp0 + dp1) % mod;
			}
		}

		ans = 1ll * ans * (dp0 + dp1) % mod;
	}

	cout << ans;

	return 0;
}