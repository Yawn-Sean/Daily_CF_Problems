void solve() {
    struct node {
        char c;
        int a, b;
    };
    int n;
    cin >> n;
    int maxst = (1 << n) - 1;
    vector<node> v(n + 100);
    vector<int> lessa(maxst), lessb(maxst);
    int sumsa = 0, sumsb = 0;

    for (int i = 0; i < n; i++) {
        cin >> v[i].c >> v[i].a >> v[i].b;
        sumsa += v[i].a;
        sumsb += v[i].b;
        for (int j = 0; j < maxst; j++) {
            if (j & (1 << i)) {
                if (v[i].c == 'R')lessa[j]++;
                else lessb[j]++;
            }
        }
    }
    vector<vector<int>> f(maxst + 1, vector<int>(n * (n + 1) / 2, -1));
    f[0][0] = 0;
    for (int i = 0; i < (1 << n); i++) {
        for (int j = 0; j < (n * (n + 1) / 2); j++) {
            if (f[i][j] < 0)continue;
            for (int k = 0; k < n; k++) {
                if (i & (1 << k))continue;
                int aa = min(v[k].a, lessa[i]);
                int bb = min(v[k].b, lessb[i]);
                int to = i | (1 << k);
                f[to][j + aa] = max(f[to][j + aa], f[i][j] + bb);
            }
        }
    }
    debug(f);
    int res = inf;
    for (int i = 0; i < (n * (n + 1) / 2); i++) {
        if (f[maxst][i] != -1) {
            res = min(res, max(sumsa - i, sumsb - f[maxst][i]));
        }
    }
    cout << res + n << endl;
}
