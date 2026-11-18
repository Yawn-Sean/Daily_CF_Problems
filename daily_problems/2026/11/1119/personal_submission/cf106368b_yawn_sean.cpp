#include <bits/stdc++.h>
#define debug(x) cerr << #x << " = " << x << endl;

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;

	vector<string> strs1(n), strs2(n);
	for (auto &s: strs1) cin >> s;
	for (auto &s: strs2) cin >> s;

	vector<vector<int>> pos1(26), pos2(26);

	long long ans = 0;

	for (int i = 0; i < n; i ++) {
		auto &s1 = strs1[i];
		auto &s2 = strs2[i];

		int k1 = s1.size();
		int k2 = s2.size();

		for (auto &c: s1) pos1[c - 'a'].emplace_back(i);
		for (auto &c: s2) pos2[c - 'a'].emplace_back(i);

		vector<vector<int>> dp(k1 + 1, vector<int>(k2 + 1, 0));

		for (int x = 0; x < k1; x ++) {
			for (int y = 0; y < k2; y ++) {
				if (s1[x] == s2[y]) dp[x + 1][y + 1] = dp[x][y] + 1;
				else dp[x + 1][y + 1] = max(dp[x][y + 1], dp[x + 1][y]);
			}
		}

		ans -= dp[k1][k2];
	}

	for (int i = 0; i < 26; i ++) {
		if (pos1[i].size() != pos2[i].size()) return cout << -1, 0;

		for (int j = 0; j < pos1[i].size(); j ++) {
			ans += abs(pos1[i][j] - pos2[i][j]) + 1;
		}
	}

	cout << ans;

	return 0;
}