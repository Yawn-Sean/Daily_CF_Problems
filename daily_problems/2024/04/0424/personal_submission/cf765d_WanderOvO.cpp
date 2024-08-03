
int T;
LL n, f[N], g[N], h[N];
vector<int> _fixed;
map<int, int> d;

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }
    for (int i = 1; i <= n; i++) {
        if (f[f[i]] != f[i]) {
            cout << "-1\n";
            return;
        }
        if (f[i] == i) {
            _fixed.pb(i);
        }
    }
    
    
    for (int i = 0; i < _fixed.size(); i++) {
        int v = _fixed[i];
        d[v] = i + 1;
    }
    
    for (int i = 1; i <= n; i++) {
        g[i] = d[f[i]];
        if (f[i] == i) {
            h[g[i]] = i;
        }
    }
    cout << _fixed.size() << "\n";
    for (int i = 1; i <= n; i++) {
        cout << g[i] << " ";
    }
    cout << "\n";
    for (int i = 1; i <= _fixed.size(); i++) {
        cout << h[i] << " ";
    }
}                                                                                                                  