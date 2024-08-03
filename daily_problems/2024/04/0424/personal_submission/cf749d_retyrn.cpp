int n, m;

void solve() {
    cin >> n;
    vector<int> last(n, -1);
    vector<vector<int>> price(n);
    for (int i = 0; i < n; i ++) {
        int x, y;
        cin >> x >> y;
        x --;
        price[x].pbk(y);
        last[x] = y;
    }
    vector<int> wait;
    for (int i = 0; i < n; i ++) {
        if (last[i] >= 0) wait.pbk(i);
    }
    sort(all(wait), [&](int x, int y) {
        return last[x] > last[y];
    });
    
    cin >> m;
    vector<int> st(n, true);
    while (m --) {
        // 找到最高价
        vector<int> ban;
        int k;
        cin >> k;
        while (k --) {
            int x;
            cin >> x;
            x --;
            ban.pbk(x);
            st[x] = false;
        }
        
        int win1 = -1, win2 = -1;
        for (auto who : wait) {
            if (!st[who]) continue;
            if (win1 == -1) win1 = who;
            else {
                win2 = who;
                break;
            }
        }
        
        if (win1 == -1) {
            cout << 0 << ' ' << 0 << endl;
        }
        else if (win2 == -1) {
            // 直接胜出
            cout << win1 + 1 << ' ' << price[win1].front() << endl;
        }
        else {
            auto p = price[win2].back();
            cout << win1 + 1 << ' ' << *ub(all(price[win1]), p) << endl;
        }
        
        for (auto x : ban) {
            st[x] = true;
        }
    }
}