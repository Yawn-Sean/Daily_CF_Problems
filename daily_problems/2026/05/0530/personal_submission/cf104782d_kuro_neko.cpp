#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define frep(i, x, y) for (int i = x; i >= y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tri tuple<int, int, int>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
struct Info {
    ll sum, maxx;
    Info(ll x = 0, ll y = 0) : sum(x), maxx(y) {}
};
Info operator+(const Info& a, const Info& b) {
    Info c;
    c.sum = a.sum + b.sum;
    c.maxx = max(b.maxx, b.sum + a.maxx);
    return c;
}
template <typename T>
class SegmentTree {
    int n;
    vector<T> tree;
    T merge_val(T a, T b) const { return a + b; }  // 合并子树

    void maintain(int node) {  // 维护整棵树
        tree[node] = merge_val(tree[node * 2], tree[node * 2 + 1]);
    }

    void build(const vector<T>& a, int node, int l, int r) {
        if (l == r) {
            tree[node] = a[l];
            return;
        }
        int m = (l + r) / 2;
        build(a, node * 2, l, m);
        build(a, node * 2 + 1, m + 1, r);
        maintain(node);
    }  // 建树

    void update(int node, int l, int r, int i, T val) {
        if (l == r) {
            tree[node] = val;
            return;
        }
        int m = (l + r) / 2;
        if (i <= m)
            update(node * 2, l, m, i, val);
        else
            update(node * 2 + 1, m + 1, r, i, val);
        maintain(node);
    }  // 更新i处的值为val

    T query(int node, int l, int r, int ql, int qr) const {
        if (ql <= l && r <= qr) return tree[node];
        int m = (l + r) / 2;
        if (qr <= m) return query(node * 2, l, m, ql, qr);
        if (ql > m) return query(node * 2 + 1, m + 1, r, ql, qr);
        T l_res = query(node * 2, l, m, ql, qr);
        T r_res = query(node * 2 + 1, m + 1, r, ql, qr);
        return merge_val(l_res, r_res);
    }  // 查询[ql,qr]的值

    int find_first(int node, int l, int r, int ql, int qr, T val) const {
        if (r < ql || l > qr) return -1;
        if (tree[node].val < val) return -1;
        if (l == r) return l;
        int m = (l + r) >> 1;
        int res = find_first(node << 1, l, m, ql, qr, val);
        if (res != -1) return res;
        return find_first(node << 1 | 1, m + 1, r, ql, qr, val);
    }
    // 若固定左端点，需要记录前缀分段最大值，并加被待求区间完全覆盖的剪枝

    int find_last(int node, int l, int r, int ql, int qr, T val) const {
        if (r < ql || l > qr) return -1;
        if (tree[node].val < val) return -1;
        if (l == r) return l;
        int m = (l + r) >> 1;
        int res = find_last(node << 1 | 1, m + 1, r, ql, qr, val);
        if (res != -1) return res;
        return find_last(node << 1, l, m, ql, qr, val);
    }

public:
    SegmentTree(int n, T init_val) : SegmentTree(vector<T>(n, init_val)) {}

    // 传入一个数组维护
    SegmentTree(const vector<T>& a) : n(a.size()), tree(2 << bit_width(a.size() - 1)) { build(a, 1, 0, n - 1); }

    void update(int i, T val) { update(1, 0, n - 1, i, val); }  // 更新i的值为val

    T query(int ql, int qr) const { return query(1, 0, n - 1, ql, qr); }  // 查询[ql,qr]的值

    T get(int i) const { return query(1, 0, n - 1, i, i); }  // 取出i处的值

    // 查询[ql,qr]中第一个满足条件的下标
    int find_first(int ql, int qr, T val) const { return find_first(1, 0, n - 1, ql, qr, val); }

    // 查询[ql,qr]中最后一个满足条件的下标
    int find_last(int ql, int qr, T val) const { return find_last(1, 0, n - 1, ql, qr, val); }
};
void solve() {
    ll n, l, r, q;
    cin >> n;
    vl a(n);
    rep(i, 0, n - 1) cin >> a[i];
    vl b(n);
    rep(i, 0, n - 1) cin >> b[i];
    cin >> q;
    vector<Info> init(n);
    rep(i, 0, n - 1) init[i] = Info(b[i] - a[i], b[i]);
    SegmentTree<Info> seg(init);
    rep(i, 0, q - 1) {
        cin >> l >> r;
        l--, r--;
        cout << seg.query(l, r).maxx << endl;
    }
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    solve();
    return 0;
}
