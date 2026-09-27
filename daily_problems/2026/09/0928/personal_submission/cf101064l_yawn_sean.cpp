#include <bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, S;
	cin >> n >> S;

	vector<long long> dp(2001, 0);
	
	while (n --) {
		int w, c;
		cin >> w >> c;

		for (int i = w; i <= 2000; i ++)
			dp[i] = max(dp[i], dp[i - w] + c);
	}

	auto dfs = [&] (auto &self, int l, int r) -> vector<long long> {
		if (r <= 2000)
			return vector<long long>(dp.begin() + l, dp.begin() + r + 1);

		int nl = max(l / 2 - 500, 0);
		int nr = r / 2 + 500;

		auto v = self(self, nl, nr);

		vector<long long> ans(r - l + 1, 0);

		for (int i = nl; i <= nr; i ++) {
			for (int j = i; j <= nr; j ++) {
				if (i + j >= l && i + j <= r) {
					ans[i + j - l] = max(ans[i + j - l], v[i - nl] + v[j - nl]);
				}
			}
		}

		return ans;
	};

	cout << dfs(dfs, S, S)[0];

	return 0;
}