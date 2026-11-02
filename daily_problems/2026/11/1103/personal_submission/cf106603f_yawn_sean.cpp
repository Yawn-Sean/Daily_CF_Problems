#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<int> vals(n + 1);

	for (int i = 0; i < n; i ++) {
		int s, v;
		cin >> s >> v;
		vals[s] = max(vals[s], v);
	}

	int cur = 0;
	vector<long long> dp(n + 1, 0);

	for (int i = 1; i <= n; i ++) {
		if (vals[i] > cur) {
			cur = vals[i];
			for (int j = i; j <= n; j ++) {
				dp[j] = max(dp[j], dp[j - i] + vals[i]);
			}
		}
		cout << dp[i] << " \n"[i == n];
	}

	return 0;
}