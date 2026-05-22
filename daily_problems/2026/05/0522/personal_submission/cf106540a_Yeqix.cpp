#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

constexpr int md = 998244353;

void solve() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	vector<int> hs(1, 1), nxt(n);
	for (int i = 1, j = 0; i < n; i++) {
		while (j && s[i] != s[j]) {
			j = nxt[j - 1];
		}
		j += (s[i] == s[j]);
		nxt[i] = j;
		if (!nxt[i]) {
			hs.push_back(i + 1);
		}
	}

	vector<i64> dp(k + 1);
	dp[0] = 1;
	for (int i = 1; i <= k; i++) {
		for (const auto& v : hs) {
			if (v > i) {
				break;
			}
			dp[i] = (dp[i] + dp[i - v]) % md;
		}
	}

	cout << dp[k] << "\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}