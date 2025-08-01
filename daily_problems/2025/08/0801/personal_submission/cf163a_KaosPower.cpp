#include<bits/stdc++.h>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s1, s2;
    cin >> s1 >> s2;

    int n1 = s1.size(), n2 = s2.size();

    vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, 0));
    int ans = 0;

    int mod = 1e9 + 7;

    auto add = [&] (int &x, int y) -> void {
        x += y;
        if (x >= mod) x -= mod;
    };

    for (int i = 0; i < n1; i ++) {
        dp[i][0] = 1;
        for (int j = 0; j < n2; j ++) {
            add(dp[i][j + 1], dp[i][j]);
            if (s1[i] == s2[j]) {
                add(dp[i + 1][j + 1], dp[i][j]);
                add(ans, dp[i][j]);
            }
        }
    }

    cout << ans;

    return 0;
}
