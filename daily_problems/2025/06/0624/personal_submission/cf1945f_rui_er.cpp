const int N = 2e5 + 5;

int T, n, v[N], p[N], rt[N];

struct PersSegTree {
    int cnt[N << 6], lc[N << 6], rc[N << 6], sz;
    void clear() {
        rep(i, 0, sz) cnt[i] = lc[i] = rc[i] = 0;
        sz = 0;
    }
    void pushup(int u) {
        cnt[u] = cnt[lc[u]] + cnt[rc[u]];
    }
    int copy(int u) {
        int v = ++sz;
        cnt[v] = cnt[u];
        lc[v] = lc[u];
        rc[v] = rc[u];
        return v;
    }
    int insert(int u, int l, int r, int val, int diff) {
        int v = copy(u);
        if(l == r) cnt[v] += diff;
        else {
            int mid = (l + r) / 2;
            if(val <= mid) lc[v] = insert(lc[u], l, mid, val, diff);
            else rc[v] = insert(rc[u], mid + 1, r, val, diff);
            pushup(v);
        }
        return v;
    }
    int kth(int u, int l, int r, int k) {
        if(l == r) return l;
        int mid = (l + r) / 2;
        if(cnt[rc[u]] >= k) return kth(rc[u], mid + 1, r, k);
        else return kth(lc[u], l, mid, k - cnt[rc[u]]);
    }
}psgt;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    for(cin >> T; T; --T) {
        cin >> n;
        rep(i, 1, n) cin >> v[i];
        rep(i, 1, n) cin >> p[i];
        per(i, n, 1) rt[i] = psgt.insert(rt[i + 1], 0, 1000000000, v[p[i]], 1);
        ll ans = -1e18, cnt = n + 1;
        rep(i, 1, n) {
            ll now = 1LL * psgt.kth(rt[i], 0, 1000000000, i) * i;
            if(now > ans) ans = now, cnt = i;
        }
        cout << ans << " " << cnt << endl;
        psgt.clear();
        rep(i, 1, n + 1) rt[i] = 0;
    }
    return 0;
}
