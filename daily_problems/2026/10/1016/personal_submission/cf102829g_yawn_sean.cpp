#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, mod = 1e9 + 7, M = 1e4;
	vector<int> dp(M + 1, 0), ndp(M + 1, 0);

	cin >> n;

	int ans = 0;

	while (n --) {
		int x;
		cin >> x;

		dp[M / 2] += 1;

		for (int i = 0; i <= M; i ++) {
			if (i >= x) ndp[i - x] += dp[i];
			if (i + x <= M) ndp[i + x] += dp[i];
		}

		for (int i = 0; i <= M; i ++) {
			dp[i] = ndp[i] % mod;
			ndp[i] = 0;
		}

		ans = (ans + dp[M / 2]) % mod;
	}

	cout << ans;

	return 0;
}