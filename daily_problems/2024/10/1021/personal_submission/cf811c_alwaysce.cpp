#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin >> n;
	vector<int> a(n);
	
	vector<int> cnt(5001), ls(5001), rs(5001);
	for (int i = 0; i < n; i++) { 
		cin >> a[i];
		rs[a[i]] = i;
	}
	
	for (int i = n - 1; i >= 0; i--) {
		ls[a[i]] = i;
	}

	vector<int> dp(n + 1);
	dp[0] = 0;
	
	for (int i = 0; i < n; i++) {
		int r = 0, _xor = 0;
		
		for (int j = i; j < n; j++) {
			if (ls[a[j]] < i) {
				break;
			}
			
			++cnt[a[j]];
			if (cnt[a[j]] == 1) {
				_xor ^= a[j];
			}
			
			if (rs[a[j]] > r) {
				r = rs[a[j]];
			}
			
			if (j == r) {
				dp[j + 1] = max(dp[j + 1], dp[i] + _xor);
			}
		}
		
		dp[i + 1] = max(dp[i + 1], dp[i]);
		for (int j = 0; j <= 5000; j++) {
			cnt[j] = 0;
		}
	}

	int ans = dp[n]; // *max_element(dp.begin(), dp.end());
	cout << ans;
    return 0;
}
