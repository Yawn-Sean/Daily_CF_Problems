// https://codeforces.com/contest/946/submission/255315449

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    string s;
    cin >> s;
    int n = s.size();
    if (s <= "1" + string(n - 2, '0') + "1") {
        cout << string(n - 2, '9') << endl;
        return;
    }
    int mask = 0;
    for (char x: s) mask ^= 1 << (x - '0');
    for (int i = n - 1; i >= 0; --i) {
        mask ^= 1 << (s[i] - '0');
        for (int x = s[i] - '0' - 1; x >= 0; --x) {
            mask ^= 1 << x;
            if (__builtin_popcount(mask) <= n - 1 - i) {
                s[i] = x + '0';
                string t;
                while (mask) {
                    t += __lg(mask & -mask) + '0';
                    mask &= mask - 1;
                }
                while (t.size() < n - 1 - i) t += '9';
                ranges::reverse(t);
                cout << s.substr(0, i + 1) << t << endl;
                return;
            }
            mask ^= 1 << x;
        }
    }
    assert(false);
}
