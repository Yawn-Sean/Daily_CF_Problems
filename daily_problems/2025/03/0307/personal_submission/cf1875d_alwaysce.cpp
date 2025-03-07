#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n), cnt(n + 1);
        for (auto&x: nums) {
            cin >> x;
            if (x <= n) {
                ++cnt[x];
            }
        }

        int mex = 0;
        while (cnt[mex] > 0) {
            mex++;
        }

        vector<i64> dp(n + 1, 1e15);
        dp[mex] = 0;

        for (int i = mex; i >= 1; i--) {
            for (int j = 0; j < i; j++) {
                dp[j] = min(dp[j], dp[i] + 1ll * i * cnt[j]);
            }
        }
        cout << dp[0] - mex << '\n';
        /*
            操作1次 mex能变成哪些值?
            2次
            n次...
            dp[i]: MEX(a) = i 没有删除任何的x, x < i 时 得到的 m的最小值
            for j < i:
                # 删除j cnt[j]次
                dp[j] = min(dp[i] + i * cnt[j])
            初始 一次都没有操作 dp[mex] = 0
            最终mex操作成0了就不用再考虑了
            需要让 mex从i变成j
            需要把j全部删掉 cnt[j]次
            产生增量=i*cnt[j]
        */

    }
    return 0;
}
