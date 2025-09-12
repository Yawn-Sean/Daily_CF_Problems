#include <bits/stdc++.h>
#pragma GCC optimize("O3,Ofast,unroll-loops")
// #include "atcoder/all"

using namespace std;
auto rng = mt19937(random_device()());
auto rngl = mt19937_64(random_device()());

// Let's set a bit and flow!
// I came, I divided, I conquered!
// using namespace __gnu_cxx;
// using namespace __gnu_pbds;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    string s;

    cin >> n >> s;

    int inf = 1e6;

    vector<int> dp(n + 1, -inf), pre(n + 1, -1), saved_ans(26, -inf), saved_pos(26, -1);
    dp[0] = 0;

    for (int i = 1; i < n; i ++) {
        if (dp[i - 1] > saved_ans[s[i - 1] - 'a']) {
            saved_ans[s[i - 1] - 'a'] = dp[i - 1];
            saved_pos[s[i - 1] - 'a'] = i - 1;
        }

        if (saved_ans[s[i] - 'a'] >= 0) {
            dp[i + 1] = saved_ans[s[i] - 'a'] + 1;
            pre[i + 1] = saved_pos[s[i] - 'a'];
        }
    }

    if (dp[n] < 0) cout << -1;
    else {
        cout << dp[n] << '\n';

        vector<int> tmp;
        int cur = n;
        while (cur) {
            tmp.emplace_back(cur - pre[cur]);
            cur = pre[cur];
        }

        reverse(tmp.begin(), tmp.end());
        for (auto &x: tmp) cout << x << ' ';
    }

    return 0;
}