#include <bits/stdc++.h>
using namespace std;

void work() {
    int n, m, k; cin >> n >> m >> k;

    vector<int> xs(n); vector<char> x_set(1e6 + 1);
    vector<int> ys(m); vector<char> y_set(1e6 + 1);

    for (int i = 0; i < n; ++i) {
        cin >> xs[i];
        x_set[xs[i]] = 1;
    }
    for (int i = 0; i < m; ++i) {
        cin >> ys[i];
        y_set[ys[i]] = 1;
    }

    vector<pair<int, int>> leak_x, leak_y;
    for (int i = 0; i < k; ++i) {
        int x, y;
        cin >> x >> y;
        if (!x_set[x]) leak_x.emplace_back(x, y);
        if (!y_set[y]) leak_y.emplace_back(y, x);
    }

    sort(leak_x.begin(), leak_x.end());
    sort(leak_y.begin(), leak_y.end());
    xs.push_back(1e9);
    ys.push_back(1e9);

    long long ans = 0;

    auto xf_iter = leak_x.begin();
    for (auto elm: xs) {
        int cur_sz = 0;
        map<int, int> line_pt_cnt;
        while (xf_iter!= leak_x.end() && xf_iter->first < elm) {
            ++cur_sz;
            line_pt_cnt[xf_iter->second] ++;
            ++xf_iter;
        }
        if (cur_sz) {
            ans += 1ll * cur_sz * (cur_sz - 1) / 2;
            for (auto [lpos, pcnt] : line_pt_cnt) {
                ans -= 1ll * pcnt * (pcnt - 1) / 2;
            }
        }
    }

    auto yf_iter = leak_y.begin();
    for (auto elm: ys) {
        int cur_sz = 0;
        map<int, int> line_pt_cnt;
        while (yf_iter!= leak_y.end() && yf_iter->first < elm) {
            ++cur_sz;
            line_pt_cnt[yf_iter->second] ++;
            ++yf_iter;
        }
        if (cur_sz) {
            ans += 1ll * cur_sz * (cur_sz - 1) / 2;
            for (auto [lpos, pcnt] : line_pt_cnt) {
                ans -= 1ll * pcnt * (pcnt - 1) / 2;
            }
        }
    }

    cout << ans << "\n";
}

int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T {1};
    cin >> T;

    while (T--) {
        work();
    }
}