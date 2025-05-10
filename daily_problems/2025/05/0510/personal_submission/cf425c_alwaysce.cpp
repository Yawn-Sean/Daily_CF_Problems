#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

    int n, m, s, e;
    cin >> n >> m >> s >> e;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }

    vector<vector<int>> pos2(100005);
    for (int i = 0; i < m; i++) {
        pos2[b[i]].push_back(i);
    }

    vector<int> dp(n + 1, 0); // dp[idx][cnt] a取到idx下标 操作次数=cnt的时候 在b序列能取到的最小下标是?
    vector<int> ndp(n + 1, 1e9);
    int ans = 0;
    for (int op = 1; op <= s / e; op++) {
        int cur = 1e9;
        for (int i = 1; i <= n; i++) {
            cur = min(cur, dp[i - 1]);
            int p = lower_bound(pos2[a[i - 1]].begin(), pos2[a[i - 1]].end(), cur) - pos2[a[i - 1]].begin();

            if (p < pos2[a[i - 1]].size()) {
                ndp[i] = pos2[a[i - 1]][p] + 1;
            }
        }
        
        for (int i = 0; i <= n; i++) {
            dp[i] = ndp[i];
            ndp[i] = 1e9;        
        }

        for (int i = 1; i <= n; i++) {
            if (dp[i] < inf && op * e + i + dp[i] <= s) {
                ans = op;
            }
        }
    
    }
    cout << ans << '\n';
    return 0;
}
