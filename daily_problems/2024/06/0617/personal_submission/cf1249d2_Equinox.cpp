#include <bits/stdc++.h>
using i64 = long long;
using i128 = __int128;
using PII = std::pair<int, int>;

template<class T> 
struct SegmentTree {
#define lc p << 1
#define rc p << 1 | 1
    struct Node {
        int l, r;
        T s, ma, lz;
    };
    std::vector<Node> tr;
    SegmentTree(int n): tr(2 << (32 - __builtin_clz(n))) {
        build(1, 1, n);
    }

    void build(int p, int l, int r) {
        tr[p] = { l, r, 0, 0, 0 };
        if (l == r) return;
        int mid = l + r >> 1;

        build(lc, l, mid);
        build(rc, mid + 1, r);
    }

    void pushdown(int p) {
        if (tr[p].lz) {
            tr[lc].s += (tr[lc].r - tr[lc].l + 1) * tr[p].lz;
            tr[rc].s += (tr[rc].r - tr[rc].l + 1) * tr[p].lz;
            tr[lc].lz += tr[p].lz;
            tr[rc].lz += tr[p].lz;
            tr[lc].ma += tr[p].lz, tr[rc].ma += tr[p].lz;
            tr[p].lz = 0;
        }
    }

    void pushup(int p) {
        tr[p].s = tr[lc].s + tr[rc].s;
        tr[p].ma = std::max(tr[lc].ma, tr[rc].ma);
    }

    void update(int p, int l, int r, T k) {
        if (l <= tr[p].l && tr[p].r <= r) {
            tr[p].lz += k;
            tr[p].ma += k;
            tr[p].s += (tr[p].r - tr[p].l - 1) * k;
            return;
        }
        pushdown(p);
        int mid = tr[p].l + tr[p].r >> 1;
        if (l <= mid) update(lc, l, r, k);
        if (r > mid) update(rc, l, r, k);
        pushup(p);
    }
};




void solve() {
    int N, K;
    std::cin >> N >> K;
    std::vector<std::array<int, 3>> segs(N);
    for (int i = 0; i < N; i ++ )
        std::cin >> segs[i][0] >> segs[i][1], segs[i][2] = i + 1;
    std::sort(segs.begin(), segs.end(), [](auto& x, auto& y) {
        return x[1] < y[1];
    });
    std::vector<int> ans;
    SegmentTree<int> st(200005);
    for (int i = 0; i < N; i ++ ) {
        auto [l, r, idx] = segs[i];
        st.update(1, l, r, 1);
        if (st.tr[1].ma > K) {
            st.update(1, l, r, -1);
            ans.push_back(idx);
        }
    }
    std::cout << ans.size() << '\n';
    for (int i = 0, m = ans.size(); i < m; i ++ )
        std::cout << ans[i] << " \n"[i == m - 1];
}


int main(int argc, char** argv) {
    std::ios::sync_with_stdio(false), std::cin.tie(0), std::cout.tie(0);
    int _ = 1;
    // std::cin >> _;
    while (_ --)
        solve();
    return 0;
}