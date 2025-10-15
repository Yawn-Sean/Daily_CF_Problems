const int N = 2e5 + 5;

int T, n, m, a[N];

struct Node {
    int max1, min1, ans1, max2, min2, ans2; // 1: a[l] > a[r]; 2: a[l] < a[r]
    Node() = default;
    Node(int max1, int min1, int ans1, int max2, int min2, int ans2): 
        max1(max1), min1(min1), ans1(ans1), max2(max2), min2(min2), ans2(ans2) {}
    friend Node operator+(Node a, Node b) {
        return Node(
            max(a.max1, b.max1), 
            min(a.min1, b.min1), 
            max({a.ans1, b.ans1, a.max1 - b.min1}), 
            max(a.max2, b.max2), 
            min(a.min2, b.min2), 
            max({a.ans2, b.ans2, b.max2 - a.min2})
        );
    }
};
struct SegTree {
    Node t[N << 2];
    #define lc(u) (u << 1)
    #define rc(u) (u << 1 | 1)
    void build(int* a, int u, int l, int r) {
        if(l == r) {
            t[u] = Node(a[l] + l, a[l] + l, 0, a[l] - l, a[l] - l, 0);
            return;
        }
        int mid = (l + r) >> 1;
        build(a, lc(u), l, mid);
        build(a, rc(u), mid + 1, r);
        t[u] = t[lc(u)] + t[rc(u)];
    }
    void modify(int u, int l, int r, int key, int val) {
        if(l == r) {
            t[u] = Node(val + l, val + l, 0, val - l, val - l, 0);
            return;
        }
        int mid = (l + r) >> 1;
        if(key <= mid) modify(lc(u), l, mid, key, val);
        else modify(rc(u), mid + 1, r, key, val);
        t[u] = t[lc(u)] + t[rc(u)];
    }
    #undef lc
    #undef rc
}sgt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(cin >> T; T; --T) {
        cin >> n >> m;
        rep(i, 1, n) cin >> a[i];
        sgt.build(a, 1, 1, n);
        cout << max(sgt.t[1].ans1, sgt.t[1].ans2) << endl;
        while(m--) {
            int key, val;
            cin >> key >> val;
            sgt.modify(1, 1, n, key, val);
            cout << max(sgt.t[1].ans1, sgt.t[1].ans2) << endl;
        }
    }
    return 0;
}
