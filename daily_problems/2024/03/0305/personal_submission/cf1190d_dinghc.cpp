#include <bits/stdc++.h>

using namespace std;
using int64 = long long;

struct fenwick_tree {
    vector<int> bit;  // binary indexed tree
    int n;
    int total;

    fenwick_tree(int n): n(n + 1), bit(n + 1, 0), total(0) {}

    int leq(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            ret += bit[idx];
        }
        return ret;
    }

    int gt(int idx) {
        return total - leq(idx);
    }

    void add(int idx, int delta = 1) {
        for (++idx; idx < n; idx += idx & -idx) {
            bit[idx] += delta;
        }
        total += 1;
    }
};

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> points(n);
    vector<int> x_cords(n);
    vector<int> y_cords(n);
    for (int i = 0; i < n; i++) {
        auto& [x, y] = points[i];
        cin >> x >> y;
        x_cords[i] = x;
        y_cords[i] = y;
    }

    ranges::sort(x_cords);
    auto rng = ranges::unique(x_cords);
    x_cords.erase(rng.begin(), rng.end());

    ranges::sort(y_cords);
    rng = ranges::unique(y_cords);
    y_cords.erase(rng.begin(), rng.end());

    int m = y_cords.size();
    vector<vector<int>> grp(m, vector<int>());
    for (auto& [x, y] : points) {
        x = ranges::lower_bound(x_cords, x) - x_cords.begin();
        y = ranges::lower_bound(y_cords, y) - y_cords.begin();
        grp[y].push_back(x);
    }

    fenwick_tree fw(x_cords.size());
    int64 ans = 0LL;
    set<int> cords;
    for (int y = m - 1; y >= 0; y--) {
        for (auto& x : grp[y]) {
            if (cords.find(x) == cords.end()) {
                fw.add(x);
                cords.insert(x);
            }
        }
        ranges::sort(grp[y]);
        int last = -1;
        for (auto& x : grp[y]) {
            // [last + 1 ~ x] * [x ~ infinity)
            int64 cnt = (static_cast<int64>(fw.leq(x)) - fw.leq(last)) * fw.gt(x - 1);
            ans += cnt;
            last = x;
        }
    }

    cout << ans << endl;

    return 0;
}
