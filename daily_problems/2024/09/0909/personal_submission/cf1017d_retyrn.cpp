int n, m, q;

int get(const string& s) {
    int res = 0;
    for (int i = 0; i < n; i ++) {
        res = res * 2 + (s[i] - '0');
    }
    return res;
}
void solve() {
    cin >> n >> m >> q;
    vector<int> w(n);
    cin >> w;
    vector<int> wei(1 << n);
    for (int i = 0; i < (1 << n); i ++) {
        int sum = 0;
        for (int j = 0; j < n; j ++) {
            if (i >> j & 1) sum += w[n - j - 1];
        }
        wei[i] = sum;
    }
    vector<int> cnt(1 << n, 0);
    for (int i = 0; i < m; i ++) {
        string s;
        cin >> s;
        int x = get(s);
        cnt[x] += 1;
    }
    
    int msk = (1 << n) - 1;
    vector<vector<int>> f(1 << n, vector<int>(101, 0));
    for (int i = 0; i < (1 << n); i ++) {
        for (int j = 0; j < (1 << n); j ++) {
            int t = i ^ j ^ msk;
            if (wei[t] > 100) continue;
            f[i][wei[t]] += cnt[j];
        }
        for (int j = 1; j <= 100; j ++) {
            f[i][j] += f[i][j - 1];
        }
    }
    
    while (q --) {
        string s;
        int k;
        cin >> s >> k;
        int x = get(s);
        cout << f[x][k] << endl;
    }
}