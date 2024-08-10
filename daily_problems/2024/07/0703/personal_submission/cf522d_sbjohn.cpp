#include <bits/stdc++.h>

#pragma GCC optimize("O3")
using namespace std;


using i64 = long long;
using pii = pair<int, int>;
//using u32 = unsigned;
constexpr int inf = INT32_MAX >> 1;
//constexpr i64 inf = INT64_MAX >> 1;
using vi = vector<int>;
using vl = vector<i64>;
using vb = vector<bool>;
#define all(x) (x).begin(),(x).end()

#define left(x) x<<1
#define right(x) x<<1|1
#define fa(x) x>>1


template<class T>
struct ST {
    struct STNode {
        T info;

        STNode() : info() {};
    };

    STNode *nodes;

    ST(int n) {
        nodes = new STNode[(n + 2) << 2];
    }

    ~ST() {
        delete[] nodes;
    }

    void pushup(int c) {
        int ls = left(c), rs = right(c);
        nodes[c].info = nodes[ls].info + nodes[rs].info;
    }

    // 单点更新
    void update(int c, int l, int r, int x, T v) {
        if (l == r) {
            nodes[c].info = v;
            return;
        }
        int mid = (l + r) >> 1;
        if (x <= mid) update(left(c), l, mid, x, v);
        else update(right(c), mid + 1, r, x, v);
        pushup(c);
    }

    void build(int c, int l, int r, vector<T> &data) {
        if (l == r) {
            nodes[c].info = data[l];
            return;
        }
        int mid = (l + r) >> 1;
        build(left(c), l, mid, data);
        build(right(c), mid + 1, r, data);
        pushup(c);
    }

    T query(int c, int l, int r, int ql, int qr) {
        if (l == ql && r == qr) {
            return nodes[c].info;
        }
        int mid = (l + r) >> 1;
        if (qr <= mid) return query(left(c), l, mid, ql, qr);
        else if (ql > mid) return query(right(c), mid + 1, r, ql, qr);
        else {
            T linfo = query(left(c), l, mid, ql, mid), rinfo = query(right(c), mid + 1, r, mid + 1, qr);
            return linfo + rinfo;
        }
    }
};

struct Info {
    int v;

    Info(int x = inf) : v(x) {}

    Info operator+(Info &a) {
        int mi = min(v, a.v);
        return {mi};
    }
};

struct Qnode {
    int l, r, id;
};

int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vi a(n + 1);
    for (int i = 1; i <= n; ++i) cin >> a[i];
    vector<Qnode> q(m);
    vi ans(m, -1);
    for (int i = 0; i < m; ++i) {
        cin >> q[i].l >> q[i].r;
        q[i].id = i;
    }
    sort(all(q), [&](const Qnode &a, const Qnode &b) {
        return a.r < b.r;
    });
    unordered_map<int, int> mp;
    ST<Info> st(n);
    int qcnt = 0;
    for (int i = 1; i <= n; ++i) {
        if (mp.contains(a[i])) {
            st.update(1, 1, n, mp[a[i]], i - mp[a[i]]);
        }
        while (qcnt < m && q[qcnt].r == i) {
            int l = q[qcnt].l, r = q[qcnt].r;
            Info t = st.query(1, 1, n, l, r);
            ans[q[qcnt].id] = t.v;
            qcnt++;
        }
        mp[a[i]] = i;
    }
    for (int i = 0; i < m; ++i)
        cout << (ans[i] == inf ? -1 : ans[i]) << endl;
}






