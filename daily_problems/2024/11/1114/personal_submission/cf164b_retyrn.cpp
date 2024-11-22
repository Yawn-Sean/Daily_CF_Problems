int n, m;

void solve() {
    cin >> n >> m;
    vector<int> a(n), b(m);
    cin >> a >> b;
    
    vector<int> pos(maxn, -1);
    
    for (int i = 0; i < m; i ++) {
        pos[b[i]] = i;
    }
    
    for (int i = 0; i < n; i ++) {
        a.push_back(a[i]);
    }
    
    int res = 0;
    int j = -1, cur = -1;
    
    auto cal = [&](int st, int ed) -> int {
        if (pos[a[ed]] >= pos[a[st]]) return pos[a[ed]];
        return pos[a[ed]] + m;
    };
    
    for (int i = 0; i < n * 2; i ++) {
        if (pos[a[i]] == -1) continue;
        if (i >= j) {
            j = i + 1;
            cur = pos[a[i]];
        }
        if (cur - m >= pos[a[i]]) cur -= m;
        while (j < n * 2 and pos[a[j]] >= 0 and j - i < n and cal(i, j) >= cur) {
            cur = cal(i, j);
            // dbg(cal(i, j), i, j);
            j ++;
        }
        chmax(res, j - i);
    }
    
    cout << res << endl;
}