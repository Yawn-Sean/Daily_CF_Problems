int n;
string s, s1, s2;

void solve() {
    vector<int> cnt(26);
    cin >> s;
    for (auto c : s) {
        cnt[c - 'a'] += 1;
    }
    vector<int> c1(26), c2(26);
    
    cin >> s1;
    for (auto c : s1) {
        c1[c - 'a'] += 1;
    }
    cin >> s2;
    for (auto c : s2) {
        c2[c - 'a'] += 1;
    }
    
    int a = 0, b = 0;
    int mx = inf;
    for (int i = 0; i < 26; i ++) {
        if (c1[i] == 0) continue;
        chmin(mx, cnt[i] / c1[i]);
    }
    for (int i = 0; i <= mx; i ++) {
        int t = inf;
        for (int j = 0; j < 26; j ++) {
            if (c2[j] == 0) continue;
            chmin(t, (cnt[j] - i * c1[j]) / c2[j]);
        }
        if (i + t > a + b) {
            a = i, b = t;
        }
    }
    
    string s;
    for (int i = 0; i < a; i ++) {
        s += s1;
    }
    for (int i = 0; i < b; i ++) {
        s += s2;
    }
    
    for (int i = 0; i < 26; i ++) {
        cnt[i] -= a * c1[i] + b * c2[i];
        while (cnt[i] > 0) {
            cnt[i] --;
            s += i + 'a';
        }
    }
    cout << s << endl;
}