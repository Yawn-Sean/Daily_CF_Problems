#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
i64 inf = 1e18;
i64 mod = 1e9+9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
    /*
        考虑到我只有一根充电线 最多只能冲一个设备
        二分会引入误差所以考虑store/power的比值
        store[i]/power[i] <= t
        s1p2<s2p1
        所以最终的充电序列就是一个按照s/p排序的一段前缀 前缀内部都是要充电的

    */
    int n, p;
    cin >> n >> p;

    vector<pair<int,int>> devices(n);
    for (auto& [x, y]: devices) {
        cin >> x >> y;
    }

    sort(devices.begin(), devices.end(), [&](auto& x, auto& y) {
        return 1ll * x.second * y.first < 1ll * y.second * x.first;
    });


    i64 cur_x = 0, cur_y = -p;
    // y = a[i], x = b[i]
    // t = sum(x) / (sum(y) - p)
    for (auto& [y, x]: devices) {
        // cur_x/cur_y > x / y
        // 只有加入后耗电比更小才会加入设备(这台设备会成为瓶颈)
        if (cur_y <= 0 || cur_x * y > cur_y * x) {
            cur_x += x; // 累加已有的电量
            cur_y += y; // 更新耗电比  cur_x / cur_y
        }
    }

    if (cur_y <= 0) {
        cout << -1;
    } else {
        cout << fixed << setprecision(10) << (long double)1.0 * cur_x / cur_y;
    }

    return 0;
}
