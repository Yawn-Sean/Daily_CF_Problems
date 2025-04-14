#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    
    int x;
    cin >> x;
    x++;

    vector<int> vals;
    while (x) {
        vals.emplace_back(x % 10);
        x /= 10;
    }
    reverse(vals.begin(), vals.end());
    
    // dp[i]: 有i个4/7的数字的数量
    // 数位dp
    // 从高到低枚举数位
    vector<i64> dp(10);
    int cnt = 0;
    for (auto&x: vals) {
        // 之前的状态
        for (int i = 9; i > 0; i--) {
            dp[i] = dp[i] * 8 + dp[i - 1] * 2;
        }
        dp[0] *= 8;
        // 当前位
        for (int i = 0; i < x; i++) {
            dp[cnt + (i == 4 || i == 7)]++;
        }
        cnt += (x == 4 || x == 7);
    }
    dp[0]--;

    function<i64(int,int)> dfs = [&](int i, int tot) -> i64 {
        if (tot > 9) {
            return 0ll;
        }
        i64 ans = 0;
        if (i < 6) {
            for (int j = 0; j < 10; j++) {
                // 试填法
                if (dp[j]) {
                    dp[j]--;
                    ans += 1ll * (dp[j] + 1) * dfs(i + 1, tot + j);
                    dp[j]++;
                }
            }
        } else {
            // 枚举第7个数字
            for (int j = tot + 1; j < 10; j++) {
                ans += 1ll * dp[j] % mod;
            }
        }
        return ans % mod;
    };

    cout << dfs(0, 0) << '\n';
    return 0;
}
