#include <bits/stdc++.h>

using namespace std;
using li = long long;

struct fenwick_tree {
    vector<int> bit;  // binary indexed tree
    int n;
    int total;
    fenwick_tree(int n): n(n + 1), bit(n + 1, 0), total(0) {}

    int less_eq(int idx) {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx) {
            ret += bit[idx];
        }
        return ret;
    }
    int less(int idx) {
        return less_eq(idx - 1);
    }
    int greater(int idx) {
        return total - less_eq(idx);
    }
    void add(int idx, int delta = 1) {
        for (++idx; idx < n; idx += idx & -idx) {
            bit[idx] += delta;
        }
        total += 1;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (auto& x : a) {
            cin >> x;
        }
        vector<int> b = a;
        ranges::sort(b);
        auto rng = ranges::unique(b);
        b.erase(rng.begin(), rng.end());
        fenwick_tree fw(b.size());
        li ans = 0LL;
        for (int i = 0; i < n; i++) {
            auto& x = a[i];
            int idx = ranges::lower_bound(b, x) - b.begin();
            ans += min(fw.less(idx), fw.greater(idx));
            fw.add(idx);
        }
        cout << ans << "\n";
    }
    return 0;
}

