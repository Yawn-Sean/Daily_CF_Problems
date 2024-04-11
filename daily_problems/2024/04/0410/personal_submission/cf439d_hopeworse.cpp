// link : https://codeforces.com/contest/439/submission/255945341
void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &i: a)cin >> i;
    vector<int> b(m);
    for (auto &i: b)cin >> i;
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<>());
    int now = 0;
    int ans = 0;
    while (now < min(n, m) && a[now] < b[now]) {
        ans += b[now] - a[now];
        now++;
    }
    cout << ans << endl;

}
