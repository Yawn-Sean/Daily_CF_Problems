#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int t;
	cin >> t;

	while (t --) {
		int n, h, k;
		cin >> n >> h >> k;

		vector<pair<int, int>> pos, neg;

		for (int i = 0; i < n; i ++) {
			int x, y;
			cin >> x >> y;

			if (y >= x) pos.emplace_back(x, y);
			else neg.emplace_back(x, y);
		}

		sort(pos.begin(), pos.end(), [&] (pair<int, int> &x, pair<int, int> &y) {
			return x.first < y.first;
		});

		sort(neg.begin(), neg.end(), [&] (pair<int, int> &x, pair<int, int> &y) {
			return x.second > y.second;
		});

		vector<long long> dp(k + 1, -1);
		dp[0] = h;

		for (auto &[x, y]: pos) {
			vector<long long> ndp(k + 1, -1);

			for (int i = 0; i <= k; i ++) {
				if (dp[i] > x) {
					ndp[i] = max(ndp[i], dp[i] - x + y);
				}
			}

			for (int i = 0; i < k; i ++) {
				ndp[i + 1] = max(ndp[i + 1], dp[i]);
			}
			
			dp.swap(ndp);
		}

		for (auto &[x, y]: neg) {
			vector<long long> ndp(k + 1, -1);

			for (int i = 0; i <= k; i ++) {
				if (dp[i] > x) {
					ndp[i] = max(ndp[i], dp[i] - x + y);
				}
			}

			for (int i = 0; i < k; i ++) {
				ndp[i + 1] = max(ndp[i + 1], dp[i]);
			}
			
			dp.swap(ndp);
		}

		cout << (*max_element(dp.begin(), dp.end()) >= 0 ? 'Y' : 'N') << '\n';
	}

	return 0;
}