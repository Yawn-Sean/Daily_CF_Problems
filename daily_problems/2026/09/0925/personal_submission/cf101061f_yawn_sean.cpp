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

	int t;
	cin >> t;

	while (t --) {
		int n;
		cin >> n;

		vector<int> dp(201, (int)1e9);
		dp[100] = 0;

		while (n --) {
			int x;
			cin >> x;

			vector<int> ndp(201, (int)1e9);

			for (int i = 0; i <= 200; i ++) {
				if (i - x >= 0) ndp[i] = min(ndp[i], dp[i - x]);
				if (i + x <= 200) ndp[i] = min(ndp[i], dp[i + x]);
				ndp[i] = max(ndp[i], abs(i - 100));
			}

			dp.swap(ndp);
		}

		cout << *min_element(dp.begin(), dp.end()) << '\n';
	}

	return 0;
}