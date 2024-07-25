const int N = 212234;

int a[N];
int pre[N];
bool st[N];

struct Node {
    int l, r;
    int mina;
} tr[N << 2];

int n, m;

void pushup(int u) {
    tr[u].mina = min(tr[u << 1].mina, tr[u << 1 | 1].mina);
}

void build(int u, int l, int r) {
    tr[u] = {l, r};
    if (l == r) {
        tr[u].mina = a[l];
        if (tr[u].mina == 0) {
            tr[u].mina = m + 1;
        }
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

int query(int u, int l, int r) {
    int res = m + 1;
    if (l <= tr[u].l && tr[u].r <= r) {
        return tr[u].mina;
    }
    int mid = tr[u].l + tr[u].r >> 1;
    if (l <= mid) res = min(res, query(u << 1, l, r));
    if (r > mid) res = min(res, query(u << 1 | 1, l, r));
    return res;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) cin >> a[i];
    build(1, 1, n);
    int cnt = 0;
    vector<pair<int, int>> fz;
    for (int i = 1; i <= n; i ++) {
        int now = a[i];
        if (now == 0) cnt ++;
        if (now == 0) continue;
        if (cnt) {
            fz.push_back({i - cnt, i - 1});
        }
        cnt = 0;
        st[now] = true;
        if (pre[now]) {
            if (pre[now] != i - 1) {
                if (query(1, pre[now] + 1, i - 1) < now) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
        }
        pre[now] = i;
    }
    if (cnt) {
        fz.push_back({n - cnt + 1, n});
    }
    if (st[m] == false) {
        if (fz.size() == 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    if (st[m] == false) {
        for (int i = fz.back().first; i <= fz.back().second; i ++) a[i] = m;
        fz.pop_back();
    }
    for (int i = 0; i < fz.size(); i ++) {
        int l = fz[i].first, r = fz[i].second;
        int now = max(a[l - 1], a[r + 1]);
        for (int j = l; j <= r; j ++) {
            a[j] = now;
        }
    }
    for (int i = 1; i <= n; i ++) {
        cout << a[i] << " \n"[i == n];
    }
    return 0;
}
