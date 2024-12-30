int n;
string s;

void solve() {
    cin >> s;
    n = sz(s);
    vector<int> pos;
    for (int i = 0; i < n; i ++) {
        if (s[i] == '1') pos.push_back(i);
    }
    if (em(pos)) {
        cout << 0 << endl;
        return;
    }
    
    // 枚举末尾的数字
    int res = 0;
    for (int i = 0; i < n; i ++) {
        auto it = upper_bound(all(pos), i);
        if (it == pos.begin()) {
            continue;
        }
        it --;
        int cur = 0;
        for (int j = it - pos.begin(); j >= 0 and cur <= n; j --) {
            if (i - pos[j] >= 20 or 1 << (i - pos[j]) > n) continue;
            cur += (1 << (i - pos[j]));
            // 看长度是否合法
            if (cur >= i - pos[j] + 1 and cur <= i - (j == 0 ? -1 : pos[j - 1])) res += 1;
        }
    }
    cout << res << endl;
}