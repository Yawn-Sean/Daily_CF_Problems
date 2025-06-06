#include <bits/stdc++.h>
using namespace std;
#define int long long

void solve() {
    int n;
    cin >> n;
    int x;
    vector<int> cnts(n+1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> x;
        if (x <= n) {
            cnts[x]++;
        }
    }
    int mex = 0;
    while (cnts[mex]) {
        ++mex;
    }
    vector<int> dp(n+5, INT_MAX);
    dp[mex] = 0;
    for (int i = mex; i >= 1; --i) {
        for (int j = i-1; j >= 0; --j) {
            dp[j] = min(dp[j], dp[i] + j + i * (cnts[j] - 1));
        }
    }
    cout << dp[0] << endl;
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}