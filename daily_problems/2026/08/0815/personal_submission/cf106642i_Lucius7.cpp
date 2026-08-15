#include <bits/stdc++.h>

#define int long long

using i64 = long long;
using u64 = unsigned long long;

template<class Info, class Tag>
struct LazySegmentTree {
    int n;
    std::vector<Info> info;
    std::vector<Tag> tag;
    LazySegmentTree() : n(0) {}
    LazySegmentTree(int n_, Info v_ = Info()) {
        init(n_, v_);
    }
    template<class T>
    LazySegmentTree(std::vector<T> init_) {
        init(init_);
    }
    void init(int n_, Info v_ = Info()) {
        init(std::vector(n_, v_));
    }
    template<class T>
    void init(std::vector<T> init_) {
        n = init_.size();
        info.assign(4 << std::__lg(n), Info());
        tag.assign(4 << std::__lg(n), Tag());
        std::function<void(int, int, int)> build = [&](int p, int l, int r) {
            if (r - l == 1) {
                info[p] = init_[l];
                return;
            }
            int m = (l + r) / 2;
            build(2 * p, l, m);
            build(2 * p + 1, m, r);
            pull(p);
        };
        build(1, 0, n);
    }
    void pull(int p) {
        info[p] = info[2 * p] + info[2 * p + 1];
    }
    void apply(int p, const Tag &v) {
        info[p].apply(v);
        tag[p].apply(v);
    }
    void push(int p) {
        apply(2 * p, tag[p]);
        apply(2 * p + 1, tag[p]);
        tag[p] = Tag();
    }
    void modify(int p, int l, int r, int x, const Info &v) {
        if (r - l == 1) {
            info[p] = v;
            return;
        }
        int m = (l + r) / 2;
        push(p);
        if (x < m) {
            modify(2 * p, l, m, x, v);
        } else {
            modify(2 * p + 1, m, r, x, v);
        }
        pull(p);
    }
    void modify(int p, const Info &v) {
        modify(1, 0, n, p, v);
    }
    Info rangeQuery(int p, int l, int r, int x, int y) {
        if (l >= y || r <= x) {
            return Info();
        }
        if (l >= x && r <= y) {
            return info[p];
        }
        int m = (l + r) / 2;
        push(p);
        return rangeQuery(2 * p, l, m, x, y) + rangeQuery(2 * p + 1, m, r, x, y);
    }
    Info rangeQuery(int l, int r) {
        return rangeQuery(1, 0, n, l, r);
    }
    void rangeApply(int p, int l, int r, int x, int y, const Tag &v) {
        if (l >= y || r <= x) {
            return;
        }
        if (l >= x && r <= y) {
            apply(p, v);
            return;
        }
        int m = (l + r) / 2;
        push(p);
        rangeApply(2 * p, l, m, x, y, v);
        rangeApply(2 * p + 1, m, r, x, y, v);
        pull(p);
    }
    void rangeApply(int l, int r, const Tag &v) {
        return rangeApply(1, 0, n, l, r, v);
    }
    
    template<class F>
    int findFirst(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        push(p);
        int res = findFirst(2 * p, l, m, x, y, pred);
        if (res == -1) {
            res = findFirst(2 * p + 1, m, r, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findFirst(int l, int r, F &&pred) {
        return findFirst(1, 0, n, l, r, pred);
    }
    template<class F>
    int findLast(int p, int l, int r, int x, int y, F &&pred) {
        if (l >= y || r <= x) {
            return -1;
        }
        if (l >= x && r <= y && !pred(info[p])) {
            return -1;
        }
        if (r - l == 1) {
            return l;
        }
        int m = (l + r) / 2;
        push(p);
        int res = findLast(2 * p + 1, m, r, x, y, pred);
        if (res == -1) {
            res = findLast(2 * p, l, m, x, y, pred);
        }
        return res;
    }
    template<class F>
    int findLast(int l, int r, F &&pred) {
        return findLast(1, 0, n, l, r, pred);
    }
};

struct Tag {
    int add = 0;
    void apply(const Tag &t) & {
        add += t.add;
    }
};

constexpr int inf = 1E15;

struct Info {
    int minv = inf, cnt = 0;
    void apply(const Tag &t) & {
        minv += t.add;
    }
};

Info operator+(const Info &a, const Info &b) {
    Info c;
    if (a.minv == b.minv) {
        c.minv = a.minv;
        c.cnt = a.cnt + b.cnt;
    } else if (a.minv < b.minv) {
        c.minv = a.minv;
        c.cnt = a.cnt;
    } else {
        c.minv = b.minv;
        c.cnt = b.cnt;
    }
    return c;
}

void solve() {
    int n, q;
    std::cin >> n >> q;

    std::vector<std::vector<int>> adj(n);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        std::cin >> x >> y;
        x--, y--;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    const int logn = std::__lg(n);
    int cur = 0;
    std::vector<int> in(n), out(n), depth(n);
    std::vector p(logn + 1, std::vector<int>(n, -1));

    auto dfs = [&](this auto &&self, int x, int fa) -> void {
        in[x] = cur++;
        p[0][x] = fa;
        for (int i = 1; i <= logn; i++) {
            p[i][x] = (p[i - 1][x] == -1 ? -1 : p[i - 1][p[i - 1][x]]);
        }
        for (auto y : adj[x]) {
            if (y == fa) {
                continue;
            }
            depth[y] = depth[x] + 1;
            self(y, x);
        }
        out[x] = cur;
    };
    dfs(0, -1);

    auto query = [&](int x, int y) {
        if (depth[x] < depth[y]) {
            std::swap(x, y);
        }

        for (int i = logn; i >= 0; i--) {
            if (depth[x] - (1 << i) >= depth[y]) {
                x = p[i][x];
            }
        }

        if (x == y) {
            return x;
        }

        for (int i = logn; i >= 0; i--) {
            if (p[i][x] != p[i][y]) {
                x = p[i][x];
                y = p[i][y];
            }
        }
        return p[0][x];
    };

    auto lift = [&](int x, int k) {
        for (int i = logn; i >= 0; i--) {
            if (k >> i & 1) {
                x = p[i][x];
            }
        }
        return x;
    };
    auto jump = [&](int x, int y, int k) {
        int lca = query(x, y);
        int dx = depth[x] - depth[lca], dy = depth[y] - depth[lca];
        if (k <= dx) {
            return lift(x, k);
        } else {
            return lift(y, dx + dy - k);
        }
    };

    std::vector<Info> info(n, {0, 1});
    LazySegmentTree<Info, Tag> t(info);

    auto apply = [&](int x, int fa, int w) {
        if (depth[x] > depth[fa]) {
            t.rangeApply(in[x], out[x], {w});
        } else {
            t.rangeApply(0, in[fa], {w});
            t.rangeApply(out[fa], n, {w});
        }
    };

    while (q--) {
        int u, v, x, y, z;
        std::cin >> u >> v >> x >> y >> z;
        u--, v--;
        if (u == v) {
            t.rangeApply(0, n, {z});
        } else {
            int lca = query(u, v);
            int d = depth[u] + depth[v] - 2 * depth[lca];
            
            if (d & 1) {
                int a = jump(u, v, d / 2), b = jump(u, v, d / 2 + 1);
                apply(a, b, x);
                apply(b, a, y);
            } else {
                t.rangeApply(0, n, {z});
                int m = jump(u, v, d / 2), a = jump(u, v, d / 2 - 1), b = jump(u, v, d / 2 + 1);
                apply(a, m, x - z);
                apply(b, m, y - z);
            }
        }

        auto ans = t.rangeQuery(0, n);
        std::cout << ans.minv << " " << ans.cnt << "\n";
    }
}

signed main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int t = 1;
    // std::cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
