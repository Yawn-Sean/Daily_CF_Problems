void solve() {
    int n;
    cin >> n;
    vector<int> f(n+1);
    for(int i=1; i<=n; i++) cin >> f[i];

    set<int> hp;

    for(int i=1; i<=n; i++) {
        if(f[f[i]] != f[i]) {
            cout << -1 << endl;
            return;
        }
        hp.insert(f[i]);
    }

    unordered_map<int, int> um;
    int idx = 1;
    for(int num: hp) {
        um[num] = idx ++;
    }

    int m = hp.size();
    vector<int> g(n+1), h(m+1);

    for(int i=1; i<=n; i++) {
        // if(hp.count(i)) {
            g[i] = um[f[i]];
            h[g[i]] = f[i];
        // }
    }

    cout << m << endl;
    for(int i=1; i<=n; i++) cout << g[i] << ' '; cout << endl;
    for(int i=1; i<=m; i++) cout << h[i] << ' '; cout << endl;

}
