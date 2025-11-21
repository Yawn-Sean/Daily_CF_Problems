#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 998244353;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n, k;
	cin >> n >> k;
	if (k == 1) {
		cout << 1;
		return 0;
	}
	
	int lim = min(n, k - 1);
	
	// dp[i]: 以i为平均值的方案数, i=1 to k
	vector<i64> dp(k + 2);
	for (int i = 1; i <= k; i++) {
		dp[i] = 1;
	}
	
	for (int i = 1; i < lim; i++) {
		vector<i64> diff(k + 2);
		int nxt = i + 1;
		for (int v = 1; v <= k; v++) {
			if (dp[v] == 0) continue;
			int l = i * v + 1;
			int r = i * v + k;
			
			int lo = (l + i) / nxt;
			int hi = r / nxt;
			if (lo <= hi) {
				diff[lo] = (diff[lo] + dp[v]) % mod;
				if (hi + 1 <= k) {
					diff[hi + 1] = (diff[hi + 1] - dp[v]) % mod;
					diff[hi + 1] = (diff[hi + 1] + mod) % mod;
				}
			}
		}
		
		i64 cur = 0;
		for (int v = 1; v <= k; v++) {
			cur = (cur + diff[v]) % mod;
			cur = (cur + mod) % mod;
			dp[v] = cur;
		}
	}
	
	i64 ans = 0;
	for (int v = 1; v <= k; v++) {
		ans = (ans + dp[v]) % mod;
	}
	cout << ans;
	return 0;
}
