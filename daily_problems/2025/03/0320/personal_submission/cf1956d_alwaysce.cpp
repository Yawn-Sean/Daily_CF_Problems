#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;

int main() {
    int n;
    cin >> n;
    vector<int> nums(n);
    for (auto&x: nums) { cin >> x;}
    
    // 先求dp的最大值
    vector<int> dp(n + 1), from(n + 1, -1);
    for (int i = 1; i <= n; i++) {
        int cur;
        for (int j = 0; j < i; j++) {
            // [j:i)操作
            cur = dp[j] + (i - j) * (i - j);
            if (cur > dp[i]) {
                dp[i] = cur;
                from[i] = j;
            }
        }
        // 不操作
        cur = dp[i - 1] + nums[i - 1];
        if (cur > dp[i]) {
            dp[i] = cur;
            from[i] = i - 1;
        }
    }

    // 构造操作
    vector<pair<int,int>> ops;
    int cur_pt = n;

    auto mex = [&](int l, int r) {
        set<int> s;
        for (int i = l; i < r; i++) {
            s.insert(nums[i]);
        }
        int v = 0;
        while (s.count(v)) {
            v++;
        }
        return v;
    };

    auto op = [&](int l, int r) {
        ops.emplace_back(l, r);
        int v = mex(l, r);
        for (int i = l; i < r; i++) {
            nums[i] = v;
        }
        return v;
    };

    auto set_zero = [&](int l, int r) {
        if (op(l, r)) {
            op(l, r);
        }
    };

    // [0, ...
    // [0, 1, ...
    // [0, 1, 2, ...
    auto dfs = [&](auto&& dfs, int l, int r) {
        if (r < 0) { return; }
        if (l + 1 == r) {
            set_zero(l, r);
        } else {
            dfs(dfs, l, r - 1);
            op(l, r);
            dfs(dfs, l, r - 1);
        }
    };

    // [l, r)
    auto process = [&](int l, int r) {
        set_zero(l, r);
        dfs(dfs, l, r);
        op(l, r);
    };

    while (cur_pt > 0) {
        int prev_pt = from[cur_pt];
        if (prev_pt < cur_pt - 1 || nums[prev_pt] == 0) {
            process(prev_pt, cur_pt);
        }
        cur_pt = prev_pt;
    }
    cout << dp[n] << ' ' << ops.size() << endl;
    for (auto& [x, y]: ops) {
        cout << x + 1 << ' ' << y << endl;
    }
    return 0;
}
