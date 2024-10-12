int n;

void solve() {
    cin >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i ++) {
        cin >> p[i];
        p[i] -= 1;
    }
    vector<int> b(n);
    cin >> b;
    
    DSU dsu(n);
    int con = n;
    for (int i = 0; i < n; i ++) {
        con -= dsu.merge(i, p[i]);
    }
    
    int sum = 0;
    for (auto x : b) {
        sum ^= x;
    }
    
    cout << (1 - sum) + (con == 1 ? 0 : con) << endl;
}