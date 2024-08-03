int n;

int ask(int x, int y) {
    cout << '?' << ' ' << x << ' ' << y << endl;
    cout.flush();
    int t;
    cin >> t;
    return t;
}

void answer(int cnt, vector<int>& res) {
    cout << '!' << endl;
    cout << cnt << endl;
    cout << res << endl;
    cout.flush();
}

void solve() {
    cin >> n;
    vector<int> u(n), v(n);
    
    for (int i = 0; i < n; i ++) {
        u[i] = ask(i, 0); // p[i] ^ b[0]
    }
    v[0] = u[0];
    for (int i = 1; i < n; i ++) {
        v[i] = ask(0, i); // p[0] ^ b[i]
    }
    
    int cnt = 0;
    vector<int> res;
    
    // 枚举 p[0]
    vector<int> b(n), p(n);
    for (int i = 0; i < n; i ++) {
        p[0] = i;
        // 求出b
        for (int j = 0; j < n; j ++) {
            b[j] = v[j] ^ p[0];
        }
        // 求出p
        for (int j = 1; j < n; j ++) {
            p[j] = u[j] ^ b[0];
        }
        
        // check
        bool ok = true;
        for (int j = 0; j < n; j ++) {
            if (b[j] >= n or p[b[j]] != j) {
                ok = false;
                break;
            }
        }
        if (ok) {
            cnt ++;
            if (em(res)) res = p;
        }
    }
    answer(cnt, res);
}