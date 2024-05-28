#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    int len = size(s);

    vector<vector<int>> dp(len, vector<int>(len));
    for (int i = 0; i < len; ++i) {
        dp[i][i] = 1;
        for (int j = 0; j <= i; ++j) {
            int dis = i - j + 1;
            if (s[i] == s[j] && (dis <= 3 || dp[j+1][i-1] > 0)) {
                if (dis / 2 - 1 >= 0 && j + dis / 2 - 1 < len) {
                    dp[j][i] = dp[j][j + dis / 2 - 1] + 1;
                }
            }
        }
    }
    
    vector<int> cnt(len + 1);
    for (int i = 0; i < len; ++i) {
        for (int j = i; j < len; ++j) {
            ++cnt[dp[i][j]];
        }
    }
    
    for (int i = len; i >= 1; --i) {
        cnt[i-1] += cnt[i];
    }
    
    for (int i = 1; i <= len; ++i) {
        cout << cnt[i] << " ";
    }
    cout << endl;
    
    return 0;
}
