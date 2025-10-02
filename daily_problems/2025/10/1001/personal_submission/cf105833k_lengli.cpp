#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;

    vector<int> hs(n), ds(n), cs(n);
    for (auto &h : hs) cin >> h;
    for (auto &d : ds) cin >> d;
    for (auto &c : cs) cin >> c;

    int inf = 1e9;
    vector<int> dp(5001, -inf);
    dp[0] = 0;

    for (int i = 0; i < n; i++) {
        int idx = n - 1 - i; // 访问原数组的倒数第i个元素
        // 逆序更新能量转移（避免覆盖）
        for (int j = 5000; j >= 0; j--) {
            if (dp[j] == -inf) continue;
            int nj = min(j + ds[idx], 5000);
            int candidate = dp[j] - cs[idx];
            if (candidate > dp[nj]) {
                dp[nj] = candidate;
            }
        }
        // 更新所有状态的分数
        for (int j = 0; j <= 5000; j++) {
            if (dp[j] != -inf) {
                dp[j] += min(j, hs[idx]);
            }
        }
    }

    cout << *max_element(dp.begin(), dp.end());

    return 0;
}
