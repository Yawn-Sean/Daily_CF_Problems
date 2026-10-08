#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	string s1, s2;
	cin >> s1 >> s2;

	int n = s1.size(), bound = n / 100;

	vector<int> dp(n + 1, 0);

	for (int i = 0; i < n; i ++) {
		int l = max(0, i - bound), r = min(n - 1, i + bound);

		for (int j = r; j >= l; j --) {
			if (s1[i] == s2[j]) {
				dp[j + 1] = dp[j] + 1;
			}
		}

		for (int j = l; j <= r; j ++) {
			dp[j + 1] = max(dp[j + 1], dp[j]);
		}
	}

	cout << (dp[n] >= n - bound ? "Long lost brothers D:" : "Not brothers :(");

	return 0;
}