#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int MOD = 1e9 + 7;

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> vec(n);
    for (int& v : vec) {
        cin >> v;
    }

    int l = -1, r = m + 1;
    while (l + 1 < r) {
        int mid = l + (r - l) / 2;

        bool flag = true;
        int pre = 0;
        for (int i = 0; i < n; ++i) {
            if (vec[i] <= pre) {
                if (pre - vec[i] > mid) {
                    flag = false;
                    break;
                }
            } else {
                if (pre + m - vec[i] > mid) { // 操作次数大于 mid，只能保持不变
                    pre = vec[i];
                }
            }
        }

        (flag ? r : l) = mid;
    }

    cout << r << "\n";
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout.precision(20);

    solve();

    return 0;
}
