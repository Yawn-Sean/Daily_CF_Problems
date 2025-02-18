int n, k1, k2;

void solve() {
    cin >> n;
    vector<vector<int>> g(n + 1);
    for (int i = 0; i < n - 1; i ++) {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    cin >> k1;
    vector<int> node1(k1);
    cin >> node1;
    cin >> k2;
    vector<int> node2(k2);
    cin >> node2;
    
    vector<int> st1(n + 1, false);
    vector<int> st2(n + 1, false);
    
    for (auto x : node1) {
        st1[x] = true;
    }
    for (auto x : node2) {
        st2[x] = true;
    }
    
    int who = 0;
    
    cout << "B " << node2[0] << endl;
    cout.flush();
    cin >> who;
    
    if (st1[who]) {
        cout << "C " << who << endl;
        cout.flush();
        return;
    }
    
    vector<int> seen(n + 1, false);
    seen[who] = true;
    queue<int> q;
    q.push(who);
    
    while (!em(q)) {
        auto t = q.front();
        q.pop();
        if (st1[t]) {
            cout << "A " << t << endl;
            cout.flush();
            cin >> who;
            cout << "C " << (st2[who] ? t : -1) << endl;
            cout.flush();
            return;
        }
        for (auto x : g[t]) {
            if (!seen[x]) {
                seen[x] = true;
                q.push(x);
            }
        }
    }
    
}