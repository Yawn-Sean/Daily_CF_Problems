#include <bits/stdc++.h>
#define int long long
#define endl '\n'

using namespace std;

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    int n, k;
    cin >> n >> k;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    sort(a.begin() + 1, a.end());
    int cnt1 = n % k, cnt2 = k - cnt1, len = n / k;
    vector<vector<int>> dp(cnt1 + 1, vector<int> (cnt2 + 1, 1e18));
    for (int i = 0; i <= cnt1; i++) {
        for (int j = 0; j <= cnt2; j++) {
            if (i == 0 && j == 0) {
                dp[i][j] = 0;
            } else {
                if (i != 0) {
                    dp[i][j] = min(dp[i][j], dp[i - 1][j] + a[i * (len + 1) + j * len] - a[(i - 1) * (len + 1) + j * len + 1]);
                }
                if (j != 0) {
                    dp[i][j] = min(dp[i][j], dp[i][j - 1] + a[i * (len + 1) + j * len] - a[i * (len + 1) + (j - 1) * len + 1]);
                }
            }
        }
    }
    cout << dp[cnt1][cnt2] << endl;
    return 0;
}
