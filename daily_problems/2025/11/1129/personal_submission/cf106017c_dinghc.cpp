#include <bits/stdc++.h>

using namespace std;
using int64 = long long;
constexpr int MOD = 1e9+7;

int inv(int a) {
    return a <= 1 ? a : MOD - static_cast<int64>(MOD / a) * inv(MOD % a) % MOD;
}

struct seg_tree {
    int n;
    vector<pair<int, int>> t;
    vector<int> marked;
    seg_tree(int n_) : n(n_), t(4 * n_, {1, 0}), marked(4 * n_, false) {}
    pair<int, int> apply(pair<int, int> a, pair<int, int> b) {
        auto& [ax, ay] = a;
        auto& [bx, by] = b;
        return {1LL * bx * ax % MOD, (1LL * bx * ay % MOD + by) % MOD};
    }
    void push(int v) {
        if (marked[v]) {
            t[v * 2 + 1] = apply(t[v * 2 + 1], t[v]);
            t[v * 2 + 2] = apply(t[v * 2 + 2], t[v]);
            marked[v * 2 + 1] = marked[v * 2 + 2] = true;
            marked[v] = false;
            t[v] = {1, 0};
        }
    }
    void update(int v, int l, int r, int L, int R, pair<int, int> new_val) {
        if (L >= R) return;
        if (l == L && r == R) {
            t[v] = apply(t[v], new_val);
            marked[v] = true;
        } else {
            push(v);
            int m = (l + r) / 2;
            update(v * 2 + 1, l, m, L, min(R, m), new_val);
            update(v * 2 + 2, m, r, max(L, m), R, new_val);
        }
    }
    pair<int, int> query(int v, int l, int r, int pos) {
        if (l + 1 == r) {
            return t[v];
        }
        push(v);
        int m = (l + r) / 2;
        if (pos < m) {
            return query(v * 2 + 1, l, m, pos);
        } else {
            return query(v * 2 + 2, m, r, pos);
        }
    }
    void update(int L, int R, pair<int, int> new_val) {
        return update(0, 0, n, L, R, new_val);
    }
    pair<int, int> query(int pos) {
        return query(0, 0, n, pos);
    }
};

int main() {
    int n;
    scanf("%d", &n);
    seg_tree sg(n);
    map<int, int> idx;
    for (int i = 0, cur = 0, type, x, p, q, j; i < n; i++) {
        scanf("%d", &type);
        if (type == 1) {
            scanf("%d", &x);
            sg.update(cur, cur + 1, {0, x});
            idx[i] = cur++;
        } else if (type == 2) {
            scanf("%d", &x);
            x = (x + MOD) % MOD;
            sg.update(0, cur, {1, x});
        } else if (type == 3) {
            scanf("%d %d", &p, &q);
            p = (p + MOD) % MOD;
            q = (q + MOD) % MOD;
            sg.update(0, cur, {1LL * p * inv(q) % MOD, 0});
        } else {
            scanf("%d", &j);
            int ans = sg.query(idx[j - 1]).second;
            printf("%d\n", ans);
        }
    }
    return 0;
}

