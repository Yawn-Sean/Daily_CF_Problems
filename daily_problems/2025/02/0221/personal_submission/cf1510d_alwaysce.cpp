#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
        有n个数字 一个期望的结尾数位d
        选取数字可以获取它们的乘积
        问如何选取，能够达到最大乘积，且这个乘积的末尾数位刚好是d
        还需要给出方案
        The numbers not chosen are limited.
    */
    
    int n, d;
    cin >> n >> d;
    vector<int> nums;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (d % 2 && x % 2 == 0) {
            continue;
        }
        if (d % 5 && x % 5 == 0) {
            continue;
        }
        nums.emplace_back(x);
    }

    // nums是看起来可行的数字集合
    // ? 至多只会去掉3个数字
    n = nums.size();

    // dp[j][i]: 前i项 末尾是j的时候 最小可能扔掉的乘积
    // 4个数字乘积的余数=x4
    // 能够找到其中<=2个数字乘积余数也是x4
    int bound = 1e6, inf = 1e9 + 7;
    vector<vector<int>> dp(10, vector<int>(n + 1, inf)), from(10, vector<int>(n + 1, -1));
    dp[1][0] = 1;
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < 10; j++) {
            if (dp[j][i] <= bound && dp[j][i + 1] > dp[j][i] * nums[i]) {
                dp[j][i + 1] = dp[j][i] * nums[i];
                from[j][i + 1] = j;
            }

            int nj = j * nums[i] % 10;
            if (dp[nj][i + 1] > dp[j][i]) {
                dp[nj][i + 1] = dp[j][i];
                from[nj][i + 1] = j;
            }
        }
    }

    if (dp[d][n] < inf) {
        vector<int> ans;
        int cur_d = d;
        for (int i = n; i > 0; i--) {
            int p = from[cur_d][i];
            if (dp[p][i - 1] == dp[cur_d][i] || nums[i - 1] == 1) {
                cur_d = p;
                ans.emplace_back(nums[i - 1]);
            }
        }

        if (!ans.empty()) {
            cout << ans.size() << '\n';
            for (auto&x: ans) {
                cout << x << ' ';
            }
        } else {
            cout << -1;
        }
    } else {
        cout << -1;
    }

    return 0;
}
