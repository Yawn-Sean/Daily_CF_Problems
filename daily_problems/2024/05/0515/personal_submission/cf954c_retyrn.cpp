int n;
const int inf = 1e9;
void solve() {
    cin >> n;
    vector<int> a(n);
    cin >> a;
    if (n == 1) {
        cout << "YES" << endl;
        cout << 1 << ' ' << inf << endl;
        return;
    }
    
    // 相邻两个数的差值只能是1或者y
    map<int, int> mp;
    for (int i = 1; i < n; i ++) {
        int diff = abs(a[i] - a[i - 1]);
        mp[diff] ++;
    }
    if (mp.count(0)) {
        cout << "NO" << endl;
        return;
    }
    
    int y = inf;
    if (!mp.count(1)) {
        if (sz(mp) == 1) {
            y = mp.begin()->fi;
        }
        else {
            cout << "NO" << endl;
            return;
        }
    }
    else {
        mp.erase(1);
        if (sz(mp) == 0) {
            cout << "YES" << endl;
            cout << 1 << ' ' << inf << endl;
            return;
        }
        else if (sz(mp) == 1) {
            y = mp.begin()->fi;
        }
        else {
            cout << "NO" << endl;
            return;
        }
    }
    // 模拟走一遍
    int i = (a[0] - 1) / y, j = a[0] - (i - 1) * y;
    
    for (int t = 1; t < n; t ++) {
        int ni = (a[t] - 1) / y, nj = a[t] - (ni - 1) * y;
        if (ni == i and abs(nj - j) == 1) {
            i = ni, j = nj;
            continue;
        }
        if (nj == j and abs(ni - i) == 1) {
            i = ni, j = nj;
            continue;
        }
        cout << "NO" << endl;
        return;
    }
    cout << "YES" << endl;
    cout << inf << ' ' << y << endl;
}