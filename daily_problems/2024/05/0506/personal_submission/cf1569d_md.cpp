// 0506
#include <bits/stdc++.h>
using namespace std;

using i64 = long long;

void solve() {
    int n, m, k;
    std::cin >> n >> m >> k;
    vector<int> x(n);
    copy_n(istream_iterator<int>(cin), n, begin(x));
    vector<int> y(m);
    copy_n(istream_iterator<int>(cin), m, begin(y));
    map<int, i64> cnt_y;
    map<int, i64> cnt_x;
    vector<map<int, i64>> dup_x(size(x) + 1);
    vector<map<int, i64>> dup_y(size(y) + 1);

    for (int i = 0; i < k; ++i) {
        int xp, yp;
        cin >> xp >> yp;

        auto x_idx = lower_bound(begin(x), end(x), xp) - begin(x); 
        auto y_idx = lower_bound(begin(y), end(y), yp) - begin(y);
        if (x[x_idx] == xp && y[y_idx] == yp) {
            continue;
        }

        if (x[x_idx] == xp) {
            cnt_y[y_idx]++;
            dup_x[x_idx][y_idx]++;
        } else {
            cnt_x[x_idx]++;
            dup_y[y_idx][x_idx]++;
        }
    }

    i64 sum = 0;
    for (int i = 0; i < n; ++i) {
        auto cnt = cnt_x[i];
        sum += cnt * (cnt - 1) / 2;
        for (auto[_, y_cnt] : dup_x[i]) {
            sum -= y_cnt * (y_cnt - 1) / 2;
        }
    }

    for (int i = 0; i < m; ++i) {
        auto cnt = cnt_y[i];
        sum += cnt * (cnt - 1) / 2;
        for (auto[_, x_cnt] : dup_y[i]) {
            sum -= x_cnt * (x_cnt - 1) / 2;
        }
    }

    cout << sum << endl;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 0;
    std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}