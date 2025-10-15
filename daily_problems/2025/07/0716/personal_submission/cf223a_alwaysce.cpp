#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    string s;
    cin >> s;
    int n = s.size();

    vector<int> dp(n);
    iota(dp.begin(), dp.end(), 1);

    for (int i = 1; i <= n; i++) {
        if (s[i] == ')') {
            int pre = dp[i - 1];
            if (pre > 0 && s[pre - 1] == '(') {
                dp[i] = (pre == 1 ? 0 : dp[pre - 2]);
            }
        } else if (s[i] == ']') {
            int pre = dp[i - 1];
            if (pre > 0 && s[pre - 1] == '[') {
                dp[i] = (pre == 1 ? 0 : dp[pre - 2]);
            }
        }
    }

    vector<int> preS(n + 1);
    for (int i = 0; i < n; i++) {
        preS[i + 1] = preS[i] + (s[i] == '[');
    }

    int ans = 0, ans_idx = 0;
    for (int i = 0; i < n; i++) {
        if (preS[i + 1] - preS[dp[i]] > ans) {
            ans = preS[i + 1] - preS[dp[i]];
            ans_idx = i;
        }
    }
    cout << ans << '\n';
    cout << s.substr(dp[ans_idx], ans_idx + 1 - dp[ans_idx]) << '\n';
    return 0;
}
