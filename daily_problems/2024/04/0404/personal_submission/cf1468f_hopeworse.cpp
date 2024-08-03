// link : https://codeforces.com/contest/1468/submission/254914364
void solve() {
    int n;
    cin >> n;
    int ans = 0;
    map<pair<int, int>, int> mp;
    for (int i = 1; i <= n; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        int u = (x2 - x1);
        int v = (y2 - y1);
        int g = gcd(u, v);
        u /= g;
        v /= g;
        ans += mp[make_pair(-u, -v)];
        mp[make_pair(u, v)]++;
    }
    cout << ans << endl;
}
