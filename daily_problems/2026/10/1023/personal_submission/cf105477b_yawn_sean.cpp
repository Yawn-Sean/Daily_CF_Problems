#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int mod = 1000000007;

	auto add = [&] (int &x, int y) -> void {
		x += y;
		if (x >= mod) x -= mod;
	};

	vector<vector<int>> saved(201, vector<int>(201, 0));

	for (int mx_val = 1; mx_val <= 200; mx_val ++) {
		vector<int> dp(mx_val + 1, 0);
		dp[0] = 1;

		for (int i = 1; i <= 400; i ++) {
			vector<int> ndp(mx_val + 1, 0);

			for (int j = 0; j <= mx_val; j ++) {
				if (j) add(ndp[j], dp[j - 1]);
				if (j < mx_val) add(ndp[j], dp[j + 1]);
			}

			dp.swap(ndp);
			if (i % 2 == 0) saved[mx_val][i / 2] = dp[0];
		}
	}

	for (int i = 200; i >= 1; i --) {
		for (int j = 0; j <= 200; j ++) {
			add(saved[i][j], mod - saved[i - 1][j]);
		}
	}

	int t;
	cin >> t;

	while (t --) {
		int l, h;
		cin >> l >> h;
		cout << saved[h][l] << '\n';
	}

	return 0;
}