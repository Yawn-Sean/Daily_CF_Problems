int n, m;

void solve() {
    cin >> n >> m;
    vector<int> p(3);
    p[1] = 0, p[2] = 1;
    
    while (m --) {
        int op;
        cin >> op;
        if (op == 1) {
            int x;
            cin >> x;
            if (x < 0) x += n;
            for (int i = 1; i <= 2; i ++) {
                p[i] = (p[i] + x) % n;
            }
        }
        else {
            for (int i = 1; i <= 2; i ++) {
                int nxt = p[i] ^ 1;
                p[i] = nxt;
            }
        }
    }
    vector<int> res(n);
    for (int i = 1; i <= 2; i ++) {
        int pos = p[i];
        for (int j = i; j <= n; j += 2) {
            res[pos] = j;
            pos = (pos + 2) % n;
        }
    }
    cout << res << endl;
}