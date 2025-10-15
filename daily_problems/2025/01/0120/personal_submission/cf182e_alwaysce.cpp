#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, l;
	cin >> n >> l;
	
	vector<pair<int,int>> rects(n);
	for (int i = 0; i < n; i++) {
		cin >> rects[i].first >> rects[i].second;
	}
	i64 mod = 1e9+7;	
	vector<vector<i64>> dp(2 * n + 1, vector<i64>(l + 1, 0));
	dp[2 * n][0] = 1ll;	
	
	// even for (ai,bi) / odd for (bi, ai)
	for (int i = 0; i <= l; i++) {
		for (int pre = 0; pre <= 2 * n; pre++) {
			for (int idx = 0; idx < n; idx++) {
				if (pre / 2 != idx) {
					int L;
					if (pre == 2 * n) { 
						L = 0; 
					} else if (pre % 2 == 1) {
						L = rects[pre / 2].second;
					} else if (pre % 2 == 0) {
						L = rects[pre / 2].first;
					}
					// cout << idx << ' ' << rects[idx].first << ' ' << L << '\n';
					if ((L == 0 or rects[idx].first == L) and i + rects[idx].first  <= l) {
						dp[idx * 2 + 1][i + rects[idx].first] = (dp[idx * 2 + 1][i + rects[idx].first] + dp[pre][i]) % mod;
					}
		
					if (rects[idx].first != rects[idx].second and (L == 0 or rects[idx].second == L) and i +  rects[idx].second <= l) {
						dp[idx * 2][i + rects[idx].second] = (dp[idx * 2][i + rects[idx].second] + dp[pre][i]) % mod;
					}
				}
			}
		}
	}
	
	i64 ans = 0;
	for (int i = 0; i <= 2 * n; i++) {
		ans = (ans + dp[i][l]) % mod;
	}
	cout << ans;	
	return 0;
}
