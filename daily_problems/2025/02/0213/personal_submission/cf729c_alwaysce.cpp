#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 inf = 1e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k, s, t;
    cin >> n >> k >> s >> t;
    vector<int> c(n), v(n);
    for (int i = 0; i < n; i++) {
        cin >> c[i] >> v[i];
    }
    vector<int> gas(k + 2);
    for (int i = 1; i <= k; i++) {
        cin >> gas[i];
    }
    gas[0] = 0; gas[k + 1] = s;
    sort(gas.begin(), gas.end());
    
    int mn = 0;
    // 全部用慢速模式 也至少需要这些容量
    for (int i = 1; i <= k + 1; i++) {
        mn = max(mn, gas[i] - gas[i - 1]);
    }

    /*
        加油站可以免费加油
        所以加油站之间的dis决定了用多少快速模式 + 多少慢速模式

        考虑油箱容量 v[i]

        0  gas[0]  gas[1] ... s
        油箱容量太小是肯定到不了的 所以二分容量v
    */
    auto check = [&](i64 x) {
        i64 tot = 0;
        i64 cur_tank = x;

        for (int i = 1; i <= k + 1; i++) {
            i64 dis = gas[i] - gas[i - 1];

            // 二分快速模式用了多少
            i64 left = 0, right = dis + 1;
            i64 ans = 0;
            while (left < right) {
                i64 mid = (left + right) / 2;
                
                i64 fast = mid, slow = dis - mid;
                if (fast * 2 + slow <= cur_tank) {
                    ans = mid;
                    left = mid + 1;
                } else {
                    right = mid;
                }
            }

            i64 fast = ans, slow = dis - ans;
            if (fast * 2 + slow <= cur_tank) {
                tot += fast + slow * 2;
            } else {
                return false;
            }
        }
        return tot <= t;
    };

    i64 left = mn, right = s + 1;
    while (left < right) {
        i64 mid = (left + right) / 2;
        if (!check(mid)) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    if (!check(left)) {
        cout << -1;
        return 0;
    }

    i64 ansC = inf;
    for (int i = 0; i < n; i++) {
        if (v[i] >= left) {
            ansC = min(ansC, 1ll * c[i]);
        }
    }
    cout << (ansC == inf ? -1 : ansC);
    return 0;
}
