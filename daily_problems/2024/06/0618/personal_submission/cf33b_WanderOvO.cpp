int T;
int n;
int d[M][M];
string a, b;

void solve1() {
    cin >> a >> b >> n;
    memset(d, 0x3f, sizeof d);
    for (int i = 0; i < M; i++) {
        d[i][i] = 0;
    }
    for (int i = 1; i <= n; i++) {
        string st, ed;
        int cost;
        cin >> st >> ed >> cost;
        int u = st[0] - 'a', v = ed[0] - 'a';
        d[u][v] = min(d[u][v], cost);
    }
    if (a.size() != b.size()) {
        cout << "-1\n";
        return;
    }
    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    int res = 0;
    for (int i = 0; i < a.size(); i++) {
        int u = a[i] - 'a', v = b[i] - 'a';
        int mincost = INF, target = -1;
        for (int ch = 0; ch < 26; ch++) {
            if (d[u][ch] + d[v][ch] < mincost) {
                mincost = d[u][ch] + d[v][ch];
                target = ch;
            }
        }
        if (target == -1) {
            cout << "-1\n";
            return;
        }
        res += mincost;
        a[i] = (target + 'a');
    }
    cout << res << "\n";
    cout << a << "\n";
}                                                                                                                  
