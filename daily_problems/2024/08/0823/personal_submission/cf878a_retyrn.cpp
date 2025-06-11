int n;

int get(const string& s) {
    if (s[0] == '|') return 0;
    if (s[0] == '^') return 1;
    return 2;
}
void solve() {
    cin >> n;
    vector<pii> a(n);
    for (int i = 0; i < n; i ++) {
        string s;
        int x;
        cin >> s >> x;
        a[i].fi = get(s), a[i].se = x;
    }
    
    // 每一位分开
    vector<int> res(3);
    res[2] = 1023;
    
    for (int i = 0; i < 10; i ++) {
        // 记录反转几次
        int rev = 0;
        for (int j = 0; j < n; j ++) {
            if (a[j].fi == 1) {
                if (a[j].se >> i & 1) rev += 1;
            }
            else if (a[j].fi == 0) {
                if (a[j].se >> i & 1) {
                    // 一定会变成1
                    int ans = 1;
                    for (int k = j + 1; k < n; k ++) {
                        if (a[k].fi == 1) {
                            if (a[k].se >> i & 1) ans ^= 1;
                        }
                        else if (a[k].fi == 0) {
                            if (a[k].se >> i & 1) ans = 1;
                        }
                        else {
                            if (!(a[k].se >> i & 1)) ans = 0;
                        }
                    }
                    if (ans) res[0] |= (1 << i);
                    else res[2] ^= (1 << i);
                    rev = -1;
                    break;
                }
            }
            else {
                if (!(a[j].se >> i & 1)) {
                    // 一定会变成0
                    int ans = 0;
                    for (int k = j + 1; k < n; k ++) {
                        if (a[k].fi == 1) {
                            if (a[k].se >> i & 1) ans ^= 1;
                        }
                        else if (a[k].fi == 0) {
                            if (a[k].se >> i & 1) ans = 1;
                        }
                        else {
                            if (!(a[k].se >> i & 1)) ans = 0;
                        }
                    }
                    if (ans) res[0] |= (1 << i);
                    else res[2] ^= (1 << i);
                    rev = -1;
                    break;
                }
            }
        }
        if (rev >= 0) {
            rev &= 1;
            if (rev) res[1] |= (1 << i);
        }
    }
    
    cout << 3 << endl;
    cout << "| " << res[0] << endl;
    cout << "^ " << res[1] << endl;
    cout << "& " << res[2] << endl;
}