#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int MOD = 1e9 + 7;
// 将二维坐标转换为一维坐标
int to_one(int x, int y, int k) {
    return x * (k + 1) + y;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int t;
    cin >> t;
    vector<int> arr(t);
    for (int idx = 0; idx < t; ++idx) {
        int n, k;
        cin >> n >> k;
        vector<int> dp((n + 1) * (k + 1), 0);  // dp[i][j] 表示前面还有i个板子，且当前的衰变期为j能得到的最大粒子数
        for (int j = 1; j <= k; ++j) {
            dp[to_one(0, j, k)] = 1;  // 初始未穿过任何板子时，粒子数为1
            for (int i = 1; i <= n; ++i) {
                // 当前数量 = 前面还有i-1个板子(穿过一层)，衰变期不变 + 前面还有n-i个板子(被反弹)，衰变期减一
                dp[to_one(i, j, k)] = (dp[to_one(i - 1, j, k)] + dp[to_one(n - i, j - 1, k)]) % MOD;
            }
        }
        arr[idx] = dp[to_one(n, k, k)];  // 前面有n个板子，且当前的衰变期为k能得到的最大粒子数加入答案
    }
    for (int &res : arr) {
        cout << res << endl;
    }
    return 0;
}