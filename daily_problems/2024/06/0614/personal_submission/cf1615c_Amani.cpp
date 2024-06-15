#include <bits/stdc++.h>
using namespace std;

int solve() {
    int n;
    string a, b;
    cin >> n >> a >> b;
    int cnt_a = 0, cnt_b = 0;
    for (int i = 0; i < n; ++i) {
        cnt_a += (a[i] == '1');
        cnt_b += (b[i] == '1');
    }
    int ans = INT_MAX;
    // 偶数次操作
    if (cnt_a == cnt_b) {
        int res = 0;
        for (int i = 0; i < n; ++i) {
            res += (a[i] != b[i]);  // 交换一次处理两个位置
        }
        ans = min(ans, res);
    }
    // 奇数次操作
    if (n - cnt_a + 1 == cnt_b) {  // 选择1才能反转，且当前位置不变，所以要+1
        int res = 0, f = 0;
        for (int i = 0; i < n; ++i) {
            if (a[i] == b[i]) {  // 原来相同 == 反转之后不同
                res++;
                f |= (a[i] == '1');
            }
        }
        ans = min(ans, res + 1 - f);
        // 奇数次本来要+1，若选择在1位置反转，可以少处理一位(选择哪个1位置不影响结果)
    }
    return ans < INT_MAX? ans : -1;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }
    return 0;
}