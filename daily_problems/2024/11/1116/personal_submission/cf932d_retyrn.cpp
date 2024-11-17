int n;
int fa[maxn][25];
int a[maxn];
ll sum[maxn][25];
int cnt = 0;

void update(ll p, ll w) {
    a[++ cnt] = w;
    if (a[p] >= a[cnt]) {
        fa[cnt][0] = p;
        sum[cnt][0] = a[p];
    }
    else {
        // 找到p的合法祖先节点中第一个大于等于w的
        for (int i = 20; i >= 0; i --) {
            if (!fa[p][i]) continue;
            if (a[fa[p][i]] < a[cnt]) p = fa[p][i];
        }
        fa[cnt][0] = fa[p][0];
        sum[cnt][0] = a[fa[p][0]];
    }
    
    for (int i = 1; i <= 20; i ++) {
        fa[cnt][i] = fa[fa[cnt][i-1]][i-1];
        sum[cnt][i] = sum[cnt][i-1] + sum[fa[cnt][i-1]][i-1];
    }
}

int query(int u, ll x) {
    if (a[u] > x) return 0;
    int res = 1;
    ll cur = a[u];
    
    for (int i = 20; i >= 0; i --) {
        if (!fa[u][i]) continue;
        if (cur + sum[u][i] <= x) {
            cur += sum[u][i];
            res += (1 << i);
            u = fa[u][i];
        }
    }
    return res;
}

void solve() {
    cin >> n;
    int last = 0;
    cnt = 1;
    
    while (n --) {
        int op;
        cin >> op;
        if (op == 1) {
            int r;
            ll w;
            cin >> r >> w;
            r ^= last;
            w ^= last;
            update(r, w);
        }
        else {
            int r;
            ll x;
            cin >> r >> x;
            r ^= last;
            x ^= last;
            last = query(r, x);
            cout << last << endl;
        }
    }
}