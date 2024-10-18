vector<string> g(2);

struct Node {
    int w00, w01, w10, w11;
    Node(int w00_ = inf, int w01_ = inf, int w10_ = inf, int w11_ = inf): w00(w00_), w01(w01_), w10(w10_), w11(w11_) {}
    ~Node() {}
};
struct SegmentTree {
    int n;
    std::vector<Node> node;
    #define lson(x) (x << 1)
    #define rson(x) (x << 1 | 1)
    SegmentTree(int n_) : n(n_ + 10), node(n << 2) {}
    void build(int p, int l, int r) {
        if (l == r) {
            if (g[0][l-1] == 'X') {
                if (g[1][l-1] == 'X') node[p].w00 = inf, node[p].w01 = inf, node[p].w10 = inf, node[p].w11 = inf;
                else node[p].w00 = inf, node[p].w01 = inf, node[p].w10 = inf, node[p].w11 = 0;
            }
            else {
                if (g[1][l-1] == 'X') node[p].w00 = 0, node[p].w01 = inf, node[p].w10 = inf, node[p].w11 = inf;
                else node[p].w00 = 0, node[p].w01 = 1, node[p].w10 = 1, node[p].w11 = 0;
            }
            return;
        }
        int mid = (l + r) / 2;
        build(lson(p), l, mid);
        build(rson(p), mid + 1, r);
        pushup(p);
    }
    void pushup(int p) {
        node[p] = cal(node[lson(p)], node[rson(p)]);
    }
    Node cal(const Node& l, const Node& r) {
        Node res;
        chmin(res.w00, min(l.w00 + r.w00, l.w01 + r.w10) + 1);
        chmin(res.w01, min(l.w00 + r.w01, l.w01 + r.w11) + 1);
        chmin(res.w10, min(l.w10 + r.w00, l.w11 + r.w10) + 1);
        chmin(res.w11, min(l.w11 + r.w11, l.w10 + r.w01) + 1);
        return res;
    }
    Node query(int p, int l, int r, int x, int y) {
        if (x <= l && r <= y) {
            return node[p];
        }
        int mid = (l + r) >> 1;
        Node res = 0;
        if (x >= mid + 1) res = query(rson(p), mid + 1, r, x, y);
        else if (y <= mid) res = query(lson(p), l, mid, x, y);
        else res = cal(query(lson(p), l, mid, x, mid), query(rson(p), mid + 1, r, mid + 1, y));
        return res;
    }
};
int n, m;

void solve() {
    cin >> n >> m;
    cin >> g;
    SegmentTree tree(n);
    tree.build(1, 1, n);
    
    while (m --) {
        int x, y;
        cin >> x >> y;
        x --, y --;
        pii l = mpr(x % n + 1, x / n);
        pii r = mpr(y % n + 1, y / n);
        if (l.fi > r.fi) swap(l, r);
        Node t = tree.query(1, 1, n, l.fi, r.fi);
        int res = inf;
        if (l.se == 0 and r.se == 0) chmin(res, t.w00);
        else if (l.se == 0 and r.se == 1) chmin(res, t.w01);
        else if (l.se == 1 and r.se == 0) chmin(res, t.w10);
        else if (l.se == 1 and r.se == 1) chmin(res, t.w11);
        cout << (res >= inf / 2 ? -1 : res) << endl;
    }
}