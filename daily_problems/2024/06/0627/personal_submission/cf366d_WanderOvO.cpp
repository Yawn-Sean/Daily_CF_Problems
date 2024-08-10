/*
n = 1e3, m = 3e3, 3s
一堆线段的交集假如不是空集，是 [l, r]，则 l 是某条线段 1 的，r 是某条线段 2 的
所以其实只需要枚举两个线段，算出来它们的交集 [l, r]
进一步，可以只枚举上下界，下界只可能是某条边的左端点，相当于枚举边，上界二分
后面从 1 开始走到 n， 只能走范围不小于 [l, r] 的边，能走到就说明存在，使用并查集验证连通性
*/

struct Edge {
    int u, v, l, r;
};

int T;
vector<Edge> segs;
int n, m;
int fa[N];

bool check(int lo, int hi) {
    for (int i = 1; i <= n; i++) {
        fa[i] = i;
    }
    for (int i = 0; i < m; i++) {
        if (segs[i].l <= lo && segs[i].r >= hi) {
            merge(segs[i].u, segs[i].v);
        }
    }
    return together(1, n);
}

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        int u, v, l, r;
        cin >> u >> v >> l >> r;
        segs.pb({u, v, l, r});
    }
    int res = 0;
    for (int i = 0; i < m; i++) {
        int left = segs[i].l;
        int l = left, r = 1e6, mid;
        while (l + 1 < r) {
            mid = (l + r) / 2;
            if (check(left, mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        if (check(left, r)) {
            res = max(res, r - left + 1);
        } else if (check(left, l)) {
            res = max(res, l - left + 1);
        }
    }
    if (res == 0) {
        cout << "Nice work, Dima!\n";
        return;
    }
    cout << res << "\n";
}              