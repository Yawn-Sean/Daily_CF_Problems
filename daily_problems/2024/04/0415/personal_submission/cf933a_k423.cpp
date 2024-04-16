// https://codeforces.com/contest/933/submission/256727315

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    int n;
    cin >> n;
    vector<int> f(5);
    while (n--) {
        int i;
        cin >> i;
        f[i] = max(f[i], f[i - 1]) + 1;
        f[i + 2] = max(f[i + 2], f[i + 1]) + 1;
    }
    cout << ranges::max(f) << endl;
}
