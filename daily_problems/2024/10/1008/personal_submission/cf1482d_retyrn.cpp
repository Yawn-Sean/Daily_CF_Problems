int n;

void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    vector<int> l(n), r(n);
    
    for (int i = 0; i < n; i ++) {
        l[i] = (i - 1 + n) % n;
        r[i] = (i + 1) % n;
    }
    
    queue<int> q;
    vector<int> del(n, false);
    
    for (int i = 0; i < n; i ++) {
        q.push(i);
    }
    
    vector<int> res;
    
    while (!em(q)) {
        auto t = q.front();
        q.pop();
        if (del[t]) continue;
        int nxt = r[t];
        if (gcd(a[t], a[nxt]) == 1) {
            res.push_back(nxt + 1);
            del[nxt] = true;
            r[l[nxt]] = r[nxt];
            l[r[nxt]] = l[nxt];
            q.push(t);
        }
    }
    cout << sz(res) << ' ';
    cout << res << endl;
}