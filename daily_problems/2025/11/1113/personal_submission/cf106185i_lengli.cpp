#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Fenwick {
    int n;
    vector<ll> bit; // 1-based internal
    Fenwick(int n = 0) { init(n); }
    void init(int _n) {
        n = _n;
        bit.assign(n + 1, 0);
    }
    // add val at position pos (0-based)
    void add(int pos, ll val) {
        for (int i = pos + 1; i <= n; i += i & -i) bit[i] += val;
    }
    // sum of [0, r) (0-based, r in [0..n])
    ll sum_prefix(int r) const {
        ll res = 0;
        for (int i = r; i > 0; i -= i & -i) res += bit[i];
        return res;
    }
    // sum on interval (l, r) i.e. indices l < idx < r (0-based)
    ll rsum(int l, int r) const {
        if (l + 1 >= r) return 0;
        return sum_prefix(r) - sum_prefix(l + 1);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<ll> outputs;
    while (true) {
        int n;
        if (!(cin >> n)) return 0;
        if (n == 0) break;

        vector<int> nums(2 * n);
        for (int i = 0; i < 2 * n; ++i) cin >> nums[i];

        // positions for values 0..n
        vector<vector<int>> pos(n + 1);
        for (int i = 0; i < 2 * n; ++i) {
            pos[nums[i]].push_back(i);
        }

        vector<int> to_pos(2 * n, -1);
        for (int val = 0; val <= n; ++val) {
            int k = (int)pos[val].size() / 2;
            for (int j = 0; j < k; ++j) {
                to_pos[pos[val][j]] = pos[val][j + k];
            }
        }

        Fenwick fen(2 * n);
        ll ans = 1LL * n * (n - 1) / 2;

        for (int i = 0; i < 2 * n; ++i) {
            if (to_pos[i] >= 0) {
                ans -= fen.rsum(i, to_pos[i]);
                fen.add(to_pos[i], 1);
            }
        }

        outputs.push_back(ans);
    }

    for (size_t i = 0; i < outputs.size(); ++i) {
        cout << outputs[i] << '\n';
    }

    return 0;
}
