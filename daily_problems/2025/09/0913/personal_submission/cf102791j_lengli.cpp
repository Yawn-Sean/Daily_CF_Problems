#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; 
    string s;
    cin >> n >> s;

    constexpr int INF = 1'000'000;

    vector<int> dp(n + 1, -INF), prev_idx(n + 1, -1);
    dp[0] = 0;

    struct Best { int val, pos; };
    array<Best, 26> best{};
    for (auto &b : best) b = Best{-INF, -1};

    for (int i = 1; i < n; ++i) {
        int c_prev = s[i - 1] - 'a';
        if (dp[i - 1] > best[c_prev].val) {
            best[c_prev] = {dp[i - 1], i - 1};
        }

        int c_now = s[i] - 'a';
        if (best[c_now].val >= 0) {
            dp[i + 1]     = best[c_now].val + 1;
            prev_idx[i + 1] = best[c_now].pos;
        }
    }

    if (dp[n] < 0) {
        cout << -1;
        return 0;
    }

    cout << dp[n] << '\n';
    vector<int> parts;
    for (int cur = n; cur; cur = prev_idx[cur]) {
        parts.push_back(cur - prev_idx[cur]);
    }
    reverse(parts.begin(), parts.end());
    for (int x : parts) cout << x << ' ';
    return 0;
}
