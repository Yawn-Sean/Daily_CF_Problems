int n;

void solve() {
    // 先手争取先消耗和初始点奇偶不同的
    // 后手先消耗和初始点奇偶相同的
    cin >> n;
    int start = 0;
    int x, y;
    cin >> x >> y;
    start = (x + y) & 1;
    
    vector<vector<int>> a(2);
    
    for (int i = 1; i <= n; i ++) {
        cin >> x >> y;
        int u = ((x + y) & 1) ^ start;
        a[u].pbk(i);
    }
    vector<bool> st(n + 1, false);
    
    if (sz(a[1]) <= n / 2) {
        cout << "First" << endl;
        cout.flush();
        for (int i = 0; i < n; i ++) {
            if (i & 1) {
                int x;
                cin >> x;
                st[x] = true;
            }
            else {
                while (!em(a[1]) and st[a[1].back()]) a[1].pop_back();
                if (!em(a[1])) {
                    cout << a[1].back() << endl;
                    cout.flush();
                    st[a[1].back()] = true;
                    a[1].pop_back();
                    continue;
                }
                while (!em(a[0]) and st[a[0].back()]) a[0].pop_back();
                if (!em(a[0])) {
                    cout << a[0].back() << endl;
                    cout.flush();
                    st[a[0].back()] = true;
                    a[0].pop_back();
                    continue;
                }
            }
        }
    }
    else {
        cout << "Second" << endl;
        cout.flush();
        for (int i = 0; i < n; i ++) {
            if ((i & 1) == 0) {
                int x;
                cin >> x;
                st[x] = true;
            }
            else {
                while (!em(a[0]) and st[a[0].back()]) a[0].pop_back();
                if (!em(a[0])) {
                    cout << a[0].back() << endl;
                    cout.flush();
                    st[a[0].back()] = true;
                    a[0].pop_back();
                    continue;
                }
                while (!em(a[1]) and st[a[1].back()]) a[1].pop_back();
                if (!em(a[1])) {
                    cout << a[1].back() << endl;
                    cout.flush();
                    st[a[1].back()] = true;
                    a[1].pop_back();
                    continue;
                }
            }
        }
    }
}