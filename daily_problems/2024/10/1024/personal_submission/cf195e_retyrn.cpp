int n;
int d[maxn], p[maxn];

int find(int x) {
    if (x == p[x]) return x;
    int t = p[x];
    p[x] = find(p[x]);
    d[x] = (d[x] + d[t]) % mod;
    return p[x];
}

void solve() {
    cin >> n;
    for (int i = 1; i <= n; i ++) {
        p[i] = i;
    }
    
    int res = 0;
    
    for (int i = 1; i <= n; i ++) {
        int k;
        cin >> k;
        while (k --) {
            int v, x;
            cin >> v >> x;
            int root = find(v);
            int len = ((d[v] + x) % mod + mod) % mod;
            p[root] = i;
            d[root] = len;
            res = (res + len) % mod;
        }
    }
    cout << res << endl;
}