int n, D;

void solve() {
    cin >> n >> D;
    vector<int> a(n);
    for (int i = 1; i < n - 1; i ++) {
        cin >> a[i];
    }
    
    vector<pii> pos(n);
    cin >> pos;
    
    vector<vector<ll>> d(n, vector<ll>(n, inf2));
    for (int i = 0; i < n; i ++) {
        d[i][i] = 0;
    }
    for (int i = 0; i < n; i ++) {
        for (int j = i + 1; j < n; j ++) {
            d[i][j] = (ll)(abs(pos[i].fi - pos[j].fi) + abs(pos[i].se - pos[j].se)) * D - a[j];
            d[j][i] = (ll)(abs(pos[i].fi - pos[j].fi) + abs(pos[i].se - pos[j].se)) * D - a[i];
        }
    }

    for (int k = 0; k < n; k ++) {
        for (int i = 0; i < n; i ++) {
            for (int j = 0; j < n; j ++) {
                if (i != j and i != k and j != k)
                    d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
    
    cout << d[0][n - 1] << endl;
}