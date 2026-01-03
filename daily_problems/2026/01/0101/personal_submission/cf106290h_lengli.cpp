#include <bits/stdc++.h>
using namespace std;

struct LazySegTree {
    int n;
    vector<long long> seg, lazy;

    LazySegTree(int _n) {
        n = 1;
        while (n < _n) n <<= 1;
        seg.assign(2 * n, 0);
        lazy.assign(2 * n, 0);
    }

    void push(int idx) {
        if (lazy[idx] != 0) {
            for (int c : {idx << 1, idx << 1 | 1}) {
                seg[c] += lazy[idx];
                lazy[c] += lazy[idx];
            }
            lazy[idx] = 0;
        }
    }

    void pull(int idx) {
        seg[idx] = max(seg[idx << 1], seg[idx << 1 | 1]);
    }

    void range_add(int l, int r, long long val, int idx, int nl, int nr) {
        if (r <= nl || nr <= l) return;
        if (l <= nl && nr <= r) {
            seg[idx] += val;
            lazy[idx] += val;
            return;
        }
        push(idx);
        int mid = (nl + nr) >> 1;
        range_add(l, r, val, idx << 1, nl, mid);
        range_add(l, r, val, idx << 1 | 1, mid, nr);
        pull(idx);
    }

    void apply(int l, int r, long long val) {
        range_add(l, r, val, 1, 0, n);
    }

    long long all_prod() {
        return seg[1];
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    vector<long long> outs;
    outs.reserve(t);

    while (t--) {
        int n;
        cin >> n;
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];

        vector<int> first_pos(n + 1, -1);
        vector<int> last_pos(n + 1, -1);
        vector<int> prev(n);

        for (int i = 0; i < n; i++) {
            prev[i] = last_pos[nums[i]];
            last_pos[nums[i]] = i;
            if (first_pos[nums[i]] == -1)
                first_pos[nums[i]] = i;
        }

        long long ans = 0;
        for (int i = 0; i <= n; i++) {
            if (last_pos[i] != -1)
                ans++;
        }

        LazySegTree seg(n);
        long long to_add = 0;

        for (int i = 0; i < n; i++) {
            if (last_pos[nums[i]] != i) {
                seg.apply(prev[i] + 1, i + 1, 1);
            } else if (prev[i] != -1) {
                seg.apply(0, prev[i] + 1, -1);
                seg.apply(first_pos[nums[i]] + 1,
                          last_pos[nums[i]] + 1, 1);
            }
            to_add = max(to_add, seg.all_prod());
        }

        outs.push_back(ans + to_add);
    }

    for (auto x : outs)
        cout << x << '\n';

    return 0;
}
