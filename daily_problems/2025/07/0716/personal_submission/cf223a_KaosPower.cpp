#include<bits/stdc++.h>

using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    string s;
    cin >> s;

    int n = s.size();

    vector<int> dp(n);
    iota(dp.begin(), dp.end(), 1);

    for (int i = 1; i < n; i ++) {
        if (s[i] == ')') {
            int pos = dp[i - 1];
            if (pos && s[pos - 1] == '(')
                dp[i] = (pos == 1 ? pos - 1 : dp[pos - 2]);
        }
        else if (s[i] == ']') {
            int pos = dp[i - 1];
            if (pos && s[pos - 1] == '[')
                dp[i] = (pos == 1 ? pos - 1 : dp[pos - 2]);
        }
    }

    vector<int> acc(n + 1, 0);
    for (int i = 0; i < n; i ++)
        acc[i + 1] = acc[i] + (s[i] == '[');

    int res = 0, idx = 0;
    for (int i = 0; i < n; i ++) {
        if (acc[i + 1] - acc[dp[i]] > res) {
            res = acc[i + 1] - acc[dp[i]];
            idx = i;
        }
    }

    cout << res << '\n';
    cout << s.substr(dp[idx], idx + 1 - dp[idx]) << '\n';

    return 0;
}
