#include <bits/stdc++.h>
using namespace std;

using i64 = long long;
using u64 = unsigned long long;
using i128 = __int128_t;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }

    vector<int> dif(m + 2);
    vector<int> dp(m + 1, INT_MIN);
    dp[0] = 0;
    int cnt = 0;
    auto add = [&]() -> void {
        dp[0] += dif[0];
        for (int i = 1; i <= cnt; i++) {
            dif[i] += dif[i - 1];
            dp[i] += dif[i];
        }
        dif.assign(m + 2, 0);
    };

    for (int i = 1; i <= n; i++) {
        if (!a[i]) {
            add();
            cnt++;
            for (int j = cnt; j >= 1; j--) {
                dp[j] = max(dp[j], dp[j - 1]);
            }
        } else if (a[i] < 0) {
            if (cnt < -a[i]) {
                continue;
            }
            dif[-a[i]]++, dif[cnt + 1]--;
        } else {
            if (cnt - a[i] < 0) {
                continue;
            }
            dif[0]++, dif[cnt - a[i] + 1]--;
        }
    }

    add();

    cout << *max_element(dp.begin(), dp.end());
    return 0;
}