// https://codeforces.com/contest/1056/submission/264756959
LL n, m, k;
void sol()
{
    cin >> n >> m;
    vector<PII> v2s;
    for (int x = 1; x <= m; x++) {
        v2s.push_back({x, (x * x) % m});
    } 
    LL res = 0;
    for (int x = 0; x < m; x++) {
        for (int y = 0; y < m; y++) {
            int sum = v2s[x].ss + v2s[y].ss; 
            if (sum == m || sum == 0) {
                LL delta = 1LL * (n / m + (n % m >= v2s[x].ff)) * (n / m + (n % m >= v2s[y].ff));
                res += delta;
            }
        }
    }
    cout << res << '\n';
}
