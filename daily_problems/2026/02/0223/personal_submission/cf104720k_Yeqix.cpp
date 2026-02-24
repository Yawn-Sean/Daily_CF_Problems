#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using i128 = __int128_t;

constexpr i64 inf = 1e18;

struct node {
    i64 R;
    i64 res;

    bool operator<(const node& t) const {
        if (R != t.R) {
            return R > t.R;
        }
        return res < t.res;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<array<i64, 2>> f(n);
    for (auto& [l, r] : f) {
        cin >> l >> r;
    }

    sort(f.begin(), f.end());

    vector<i64> dp(n, -inf);
    priority_queue<node> que;
    i64 pre = 0;
    for (int i = 0; i < n; i++) {
        auto [r, R] = f[i];
        while (!que.empty() && r >= que.top().R) {
            pre = max(pre, que.top().res);
            que.pop();
        }
        dp[i] = max(dp[i], pre + R * R - r * r * 2);
        que.push(node{R, dp[i] + R * R});
    }

    cout << *max_element(dp.begin(), dp.end());
    return 0;
}
