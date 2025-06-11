int n;
string s;

template<class Ty1,class Ty2> 
inline const pair<Ty1,Ty2> operator+(const pair<Ty1, Ty2>&p1, const pair<Ty1, Ty2>&p2) {
    pair<Ty1, Ty2> ret;
    ret.first = p1.first + p2.first;
    ret.second = p1.second + p2.second;
    return ret;
}

template<class Ty1, class Ty2> 
inline const pair<Ty1, Ty2> operator-(const pair<Ty1, Ty2>&p1, const pair<Ty1, Ty2>&p2) {
    pair<Ty1, Ty2> ret;
    ret.first = p1.first - p2.first;
    ret.second = p1.second - p2.second;
    return ret;
}

pii get(char c) {
    if (c == 'R') return mpr(1, 0);
    if (c == 'L') return mpr(-1, 0);
    if (c == 'U') return mpr(0, 1);
    return mpr(0, -1);
}
void solve() {
    cin >> n;
    cin >> s;
    vector<pii> f(n + 1, mpr(0, 0));
    for (int i = 1; i <= n; i ++) {
        pii t = get(s[i-1]);
        f[i] = f[i-1] + t;
    }
    
    pii tar;
    cin >> tar;
    if (abs(tar.fi) + abs(tar.se) > n) {
        cout << -1 << endl;
        return;
    }
    if ((abs(tar.fi) % 2 - abs(tar.se) % 2 + 2) % 2 != n % 2) {
        cout << -1 << endl;
        return;
    }
    if (f[n] == tar) {
        cout << 0 << endl;
        return;
    }
    
    auto check = [&](int i, int mid) {
        pii sum = f[i] + f[n] - f[n - mid];
        return abs(sum.fi - tar.fi) + abs(sum.se - tar.se) <= n - i - mid;
    };
    
    int res = n;
    for (int i = 0; i < n; i ++) {
        int l = 0, r = n - i;
        while (l < r) {
            auto mid = (l + r + 1) >> 1;
            if (check(i, mid)) l = mid;
            else r = mid - 1;
        }
        if (check(i, l)) chmin(res, n - l - i);
    }
    
    cout << res << endl;
}