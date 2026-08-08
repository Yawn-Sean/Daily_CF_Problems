#include<bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

constexpr int N = 4e5;
vector<vector<int>> fac(N + 1);
vector<deque<array<i64, 2>>> dp(N + 1);

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	i64 ans = 0;
	for (int i = 1; i <= n; i++) {
		i64 mx = 0;
		for (const auto& v : fac[a[i]]) {
			while (!dp[v].empty() && dp[v].front()[1] < i - k) {
				dp[v].pop_front();
			}
			if (!dp[v].empty()) {
				mx = max(mx, dp[v].front()[0] + v);
			}
		}

		for (const auto& v : fac[a[i]]) {
			while (!dp[v].empty() && dp[v].back()[0] <= mx) {
				dp[v].pop_back();
			}
			dp[v].push_back({mx, i});
		}
		ans = max(ans, mx);
	}

	cout << ans << "\n";
	dp.assign(N + 1, {});
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j += i) {
			fac[j].push_back(i);
		}
	}
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
	return 0;
}