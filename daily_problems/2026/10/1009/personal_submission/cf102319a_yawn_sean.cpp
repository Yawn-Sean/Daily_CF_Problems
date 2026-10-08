#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, l, r;
	cin >> n >> l >> r;

	vector<int> dp(r + 1, (int)1e9);
	dp[0] = 0;

	while (n --) {
		int x;
		cin >> x;

		for (int i = x; i <= r; i ++) {
			dp[i] = min(dp[i], dp[i - x] + 1);
		}
	}

	int cur_ans = 0, choice = 0;
	for (int i = l; i <= r; i ++) cur_ans += dp[i];

	for (int i = 2; i <= r; i ++) {
		int new_ans = 0;

		for (int j = l; j <= r; j ++) {
			int v = 1e9;
			for (int w = 0; w <= j / i; w ++) {
				v = min(v, dp[j - w * i] + w);
			}
			new_ans += v;
		}

		if (new_ans < cur_ans) {
			cur_ans = new_ans;
			choice = i;
		}
	}

	cout << choice;

	return 0;
}