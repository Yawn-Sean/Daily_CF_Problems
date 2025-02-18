int n, k;

void solve() {
    cin >> n >> k;
    vector<int> v = {0};
    for (int i = 0; i < 5; i ++) {
        vector<int> vv(all(v));
        reverse(all(vv));
        for (auto x : vv) {
            v.pbk(x ^ (1 << i * 2));
        }
    }
    vector<pii> pos(1024);
    for (int i = 0; i < 32; i ++) {
        for (int j = 0; j < 32; j ++) {
            pos[v[i] ^ (v[j] << 1)] = mpr(i + 1, j + 1);
        }
    }
    
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < n - 1; j ++) {
            cout << (v[j] ^ v[j + 1]) * 2 << ' ';
        }
        cout << endl;
    }
    for (int i = 0; i < n - 1; i ++) {
        for (int j = 0; j < n; j ++) {
            cout << (v[i] ^ v[i + 1]) << ' ';
        }
        cout << endl;
    }
    cout.flush();
    
    int cur = 0;
    while (k --) {
        int x;
        cin >> x;
        cur ^= x;
        cout << pos[cur] << endl;
        cout.flush();
    }
}