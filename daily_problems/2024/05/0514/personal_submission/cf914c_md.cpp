// 0514
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
constexpr int MOD = 1e9 + 7;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    string num;
    cin >> num;
    int k;
    cin >> k;

    int n = ssize(num);
    if (k == 0) {
        cout << 1 << endl;
        return 0;
    }

    if (k == 1) {
        cout << n - 1 << endl;
        return 0;
    }

    int digits = min(10, __lg(n) + 1);
    int num_count = (1 << digits);
    vector<int> ops(num_count);
    for (int i = 2; i < num_count; ++i) {
        ops[i] = ops[__builtin_popcount(i)] + 1;
    }

    vector<vector<i64>> memo(n, vector<i64>(num_count, -1));
    auto dfs = [&](auto self, int i, int cnt_one, bool is_limit, bool is_num) -> i64 {
        if (i == n) {
            return is_num && (ops[cnt_one] == k - 1);
        }

        if (!is_limit && is_num && memo[i][cnt_one] != -1) {
            return memo[i][cnt_one];
        }

        i64 ret = 0;
        if (!is_num) {
            ret = self(self, i + 1, cnt_one, false, false);
        }

        int up = is_limit ? num[i] - '0' : 1;
        for (int d = 1 - is_num; d <= up; ++d) {
            ret = (ret + self(self, i + 1, cnt_one + d, is_limit && (d == up), true)) % MOD;
        }

        if (!is_limit && is_num) {
            memo[i][cnt_one] = ret;
        }
        return ret;
    };

    i64 ans = dfs(dfs, 0, 0, true, false) % MOD;
    cout << ans << endl;

    return 0;
}