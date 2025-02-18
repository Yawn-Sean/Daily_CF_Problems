#include <bits/stdc++.h>

using namespace std;
constexpr int N = 200'000;
int a[N];

struct seg_tree {
    int n;
    vector<int> t;
    seg_tree(int n) : n(n) {
        t.resize(4 * n, -1);
        build(0, 0, n);
    }
    void build(int k, int l, int r) {
        if (r - l == 1) {
            t[k] = a[l];
        } else {
            build(k * 2 + 1, l, (l + r) / 2);
            build(k * 2 + 2, (l + r) / 2, r);
            t[k] = max(t[k * 2 + 1], t[k * 2 + 2]);
        }
    }
    void update(int v, int l, int r, int pos, int val) {
        if (r - l == 1) {
            t[v] = val;
            return;
        }
        int m = (l + r) >> 1;
        if (pos < m) update(v * 2 + 1, l, m, pos, val);
        else update(v * 2 + 2, m, r, pos, val);
        t[v] = max(t[v * 2 + 1], t[v * 2 + 2]);
    }
    int query(int v, int l, int r, int pos, int val) {
        if (pos >= r) return -1;
        if (r - l == 1) return t[v] >= val ? l : -1;
        int m = (l + r) >> 1;
        if (l >= pos) {
            if (t[v] < val) return -1;
            if (t[v * 2 + 1] >= val) return query(v * 2 + 1, l, m, pos, val);
            return query(v * 2 + 2, m, r, pos, val);
        }
        int j = query(v * 2 + 1, l, m, pos, val);
        if (j == -1) j = query(v * 2 + 2, m, r, pos, val);
        return j;
    }
    void update(int pos, int val) {
        return update(0, 0, n, pos, val);
    }
    int query(int pos, int val) {
        return query(0, 0, n, pos, val);
    }
};

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    seg_tree st(n);
    while (n) {
        int start = 0;
        int pre = 0;
        int pos = 0;
        while ((pos = st.query(start, pre)) != -1) {
            n--;
            printf("%d ", a[pos]);
            start = pos + 1;
            pre = a[pos];
            st.update(pos, -1);
        }
        printf("\n");
    }
    return 0;
}

