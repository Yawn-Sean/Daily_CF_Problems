#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n, idx;
    cin >> n;
    vector<int> vec(n+10, 0), dp(n+10, 0);
    for (int i = 1; i <= n; ++i) {
        cin >> vec[i];
    }
    for (int i = 1; i <= n; ++i) {
        dp[i] = dp[i-1] + 20;
        idx = lower_bound(vec.begin()+1, vec.begin()+n+1, vec[i] - 89) - vec.begin()-1;
        dp[i] = min(dp[i], dp[idx] + 50);
        idx = lower_bound(vec.begin()+1, vec.begin()+n+1, vec[i] - 1439) - vec.begin()-1;
        dp[i] = min(dp[i], dp[idx] + 120);
        cout << dp[i] - dp[i-1] << endl;
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t = 1;
//    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}