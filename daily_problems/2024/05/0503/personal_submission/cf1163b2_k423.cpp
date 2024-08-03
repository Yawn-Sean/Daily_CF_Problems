// https://codeforces.com/contest/1163/submission/259382852

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    int ans = min(n, 3);
    map<int, int> mp1, mp2;
    for (int i = 1, x; i <= n; ++i) {
        cin >> x;
        if (mp1.contains(x)) {
            mp2[mp1[x]]--;
            if (mp2[mp1[x]] == 0) {
                mp2.extract(mp1[x]);
            }
        }
        mp1[x]++;
        mp2[mp1[x]]++;
        if (mp2.size() == 1 && (mp1[x] == 1 || mp1[x] == i)) {
            ans = i;
        } else if (mp2.size() == 2) {
            if (mp2.begin()->first == 1) {
                if (mp2.begin()->second == 1 || mp2.rbegin()->first == 2 && mp2.rbegin()->second == 1) {
                    ans = i;
                }
            } else {
                if (mp2.rbegin()->second == 1 && mp2.rbegin()->first == mp2.begin()->first + 1) {
                    ans = i;
                }
            }
        }
    }
    cout << ans << endl;
}
