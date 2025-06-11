#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;

void solve() {
    string s;
    cin >> s;
    int n = s.size();
    vector<int> cnt(26);
    for (int i = 0; i < n; i++) {
        cnt[s[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
        if (cnt[i] >= 100) {
            cout << string(100, i + 'a') << endl;
            return;
        }
    }
    // 长度必定小于2600
    vector<vector<int>> dp(n + 1, vector<int>(n + 1));
    for (int i = n; i >= 1; i--) {
        dp[i][i] = 1;
        for (int j = i + 1; j <= n; j++) {
            if (s[i - 1] == s[j - 1]) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    vector<char> ret;
    int len = min(100, dp[1][n]);
    int i = 1, j = n;
    while (i <= j) {
        if (s[i - 1] == s[j - 1]) {
            ret.push_back(s[i - 1]);
            i++;
            j--;
        } else if (dp[i + 1][j] > dp[i][j - 1]) {
            i++;
        } else if (dp[i + 1][j] <= dp[i][j - 1]) {
            j--;
        }
    }
    int m = min(50, (int)ret.size());
    bool flag = len & 1;
    for (int i = 0; i < m - 1; i++) {
        cout << ret[i];
    }
    if (flag) {
        cout << ret[m - 1];
    } else {
        cout << ret[m - 1] << ret[m - 1];
    }
    for (int i = m - 2; i >= 0; i--) {
        cout << ret[i];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}