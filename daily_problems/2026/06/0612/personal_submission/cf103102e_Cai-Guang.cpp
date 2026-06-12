#include <bits/stdc++.h>

using namespace std;

using i64 = long long;

void solve() {
    int n;
    cin >> n;

    vector<int> a(n + 1);

    i64 ans = 0;

    vector<vector<array<i64, 3>>> dp(n + 1, vector<array<i64, 3>>(3, array<i64, 3>()));

    // id sum ans
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        dp[i][a[i] % 3][0] ++;
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 3; k++) {
                dp[i][(j + a[i]) % 3][(k + a[i] * j) % 3] += dp[i - 1][j][k];
            }
        }      
        
        for (int j = 0; j < 3; j++) {
            ans += dp[i][j][0];
        }
    }

    cout << ans << '\n';
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t = 1;
	
	// cin >> t;
	
	while (t --) {
		solve();
	}
} 
