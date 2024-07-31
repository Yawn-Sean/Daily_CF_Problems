#include <bits/stdc++.h>

using namespace std;
constexpr int INF = 0x3F3F3F3F;

struct seg_tree {
    int n;
    vector<int> t;
    vector<bool> marked;
    seg_tree(int _n) : n(_n), t(n * 4, INF), marked(n * 4, false) {}
    void push(int v) {
        if (marked[v]) {
            t[v * 2 + 1] = min(t[v * 2 + 1], t[v]);
            t[v * 2 + 2] = min(t[v * 2 + 2], t[v]);
            marked[v * 2 + 1] = marked[v * 2 + 2] = true;
            marked[v] = false;
        }
    }
    void update(int v, int l, int r, int L, int R, int val) {
        if (L >= R) return;
        if (l == L && r == R) {
            t[v] = min(t[v], val);
            marked[v] = true;
        } else {
            push(v);
            int m = (l + r) >> 1;
            update(v * 2 + 1, l, m, L, min(m, R), val);
            update(v * 2 + 2, m, r, max(m, L), R, val);
        }
    }
    int query(int v, int l, int r, int pos) {
        if (l + 1 == r) {
            return t[v];
        }
        push(v);
        int m = (l + r) >> 1;
        if (pos < m) {
            return query(v * 2 + 1, l, m, pos);
        } else {
            return query(v * 2 + 2, m, r, pos);
        }
    }
    void update(int L, int R, int val) {
        return update(0, 0, n, L, R, val);
    }
    int query(int pos) {
        return query(0, 0, n, pos);
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<int> b(n, INF);
    map<int, int> mp;
    for (int i = 0, x; i < n; i++) {
        cin >> x;
        auto it = mp.find(x);
        if (it != mp.end()) {
            b[i] = i - it->second;
            it->second = i;
        } else {
            mp.emplace(x, i);
        }
    }
    vector<int> beg(n, 0);
    vector<array<int, 3>> queries(m);
    for (int i = 0, l, r; i < m; i++) {
        cin >> l >> r;
        l--, r--;
        beg[l]++;
        queries[i] = array<int, 3> {l, r, i};
    }
    vector<vector<pair<int, int>>> end(n, vector<pair<int, int>>());
    ranges::sort(queries);
    for (int i = 0; i < m; i++) {
        auto& [l, r, j] = queries[i];
        end[r].emplace_back(i, j);
    }
    vector<int> ans(m, -1);
    seg_tree st(m);
    vector<int> indices(n, -1);
    for (int i = 0, tot = 0; i < n; i++) {
        tot += beg[i];
        indices[i] = tot;
        if (b[i] < INF) {
            st.update(0, indices[i - b[i]], b[i]);
        }
        for (auto& [j, k] : end[i]) {
            int res = st.query(j);
            if (res < INF) ans[k] = res;
        }
    }
    for (auto& v : ans) {
        cout << v << "\n";
    }
    return 0;
}

