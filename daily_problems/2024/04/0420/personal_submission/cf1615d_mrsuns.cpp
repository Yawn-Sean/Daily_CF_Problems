 struct DSU {
    vector<int> p, siz;
    struct info {
        int x = 0;
        friend info operator+(const info& u, const info& v) {
            int t = abs(u.x) + abs(v.x);
            if (t == 1) return { 1 };
            return { 0 };
        }
        info operator-() { return { -x }; }
        friend bool operator==(const info& u, const info& v) { return u.x == v.x; }
    };
    vector<info> val;
    DSU(int n) :p(n), siz(n, 1), val(n) { iota(p.begin(), p.end(), 0); }
    int find(int x) {
        if (x != p[x]) {
            int t = find(p[x]);
            val[x] = val[x] + val[p[x]];
            p[x] = t;
        }
        return p[x];
    }
    bool same(int x, int y) { return find(x) == find(y); }
    bool merge(int x, int y, info w) {//w为y指向x的关系,并将y并入x
        int px = find(x), py = find(y);
        if (px == py) {
            if (w + val[x] == val[y]) return 1;
            return 0;//矛盾
        }
        siz[px] += siz[py];
        p[py] = px;
        val[py] = val[x] + -val[y] + -w;//w+val[y]+val[py]=val[x]
        return 1;
    }
    int query(int x, int y) {//x指向y的关系
        int px = find(x), py = find(y);
        return (val[x] + -val[y]).x;
    }
    int size(int x) { return siz[find(x)]; }
};
 
void Solve() {
    int n, m;cin >> n >> m;
    vector<array<int, 3>> edge;
    DSU d(n + 1);
    int retNO = 0;
    for (int i = 1;i < n;i++) {
        int u, v, w;cin >> u >> v >> w;
        edge.push_back({ u,v,w });
        if (w >= 0) {
            w = Ones(w) & 1;
            if (d.merge(u, v, { w }) == 0) retNO = 1;
        }
    }
    while (m--) {
        int u, v, w;cin >> u >> v >> w;
        if (d.merge(u, v, { w }) == 0) retNO = 1;
    }
    if (retNO) return cout << "NO" << endl, void();
    cout << "YES" << endl;
    for (auto [u, v, w] : edge) {
        if (w == -1) {
            cout << u << " " << v << " " << d.query(u, v) << endl;
        }
        else {
            cout << u << " " << v << " " << w << endl;
        }
    }
 
}
