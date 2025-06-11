int n;

void solve() {
    cin >> n;
    vector<int> p(n), d(n);
    vector<int> st(n, false);
    int root = -1;
    
    int res = 0;
    
    for (int i = 0; i < n; i ++) {
        cin >> p[i];
        p[i] -= 1;
        if (i == p[i]) {
            if (root >= 0) p[i] = root, res ++;
            else root = i;
            st[i] = true;
            continue;
        }
        d[p[i]] += 1;
    }
    
    // 只有环+树
    // 找到的第一个自环做根
    queue<int> q;
    for (int i = 0; i < n; i ++) {
        if (!st[i] and d[i] == 0) {
            q.emplace(i);
            st[i] = true;
        }
    }
    
    while (!em(q)) {
        auto t = q.front();
        q.pop();
        if ((-- d[p[t]] == 0) and !st[p[t]]) {
            st[p[t]] = true;
            q.emplace(p[t]);
        }
    }
    
    // 剩下的是环
    for (int i = 0; i < n; i ++) {
        if (st[i]) continue;
        int x = i;
        st[x] = true;
        while (!st[p[x]]) {
            x = p[x];
            st[x] = true;
        }
        if (root == -1) p[x] = x, root = x;
        else p[x] = root;
        res += 1;
    }
    
    cout << res << endl;
    
    for (auto x : p) {
        cout << x + 1 << ' ';
    }
    cout << endl;
}