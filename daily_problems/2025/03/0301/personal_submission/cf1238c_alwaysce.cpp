#include <bits/stdc++.h>
using namespace std;
using i64 = long long;

i64 mod = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
        考虑什么时候才需要操作?
        当前人物在cur位置 已经站这里
        cur-1正好=0 那么正好可以到cur-1
        cur-1切换 看cur-2是否在外面 如果在外面 那么直接到cur-2 否则需要操作一次
        为什么不去操作cur-1是因为最终还是会到cur-2
        所以直接到cur-2
    */
    
    int q;
    cin >> q;
    while (q--) {
        int h, n;
        cin >> h >> n;
        vector<int> out(n + 1);
        for (int i = n; i >= 1; i--) {
            cin >> out[i];
        }
        // out[1], out[2], ..., out[n]
        // h->h-1 h-1不在out内 总是可以走到
        // h-> out[x]+1
        // out[x] out[x]+1操作 如果 out[x]-1在 那么不需要操作
        // 否则肯定要操作1次在out[x]-1位置
        vector<int> dp(n + 1);
        for (int i = 2; i <= n; i++) {
            if (out[i - 1] == out[i - 2] + 1) {
                dp[i] = dp[i - 2]; // y y - 1都在 不需要操作 肯定能到y-1
            } else {
                dp[i] = dp[i - 1] + 1; // 否则就一定要操作一次
            }
        }
        cout << dp[n] << '\n';
    }
    return 0;
}
