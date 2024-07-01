// https://codeforces.com/contest/1085/submission/267960355
int deg[MAXN];
void sol()
{
    int n, u, v;
    double s;
    cin >> n >> s;
    for (int i = 1; i < n; i++) {
        cin >> v >> u;
        deg[v]++, deg[u]++;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (deg[i] == 1)
            cnt++;
    }
    cout << fixed << showpoint;
    cout << setprecision(15);
    cout << (s / cnt) * 2 << '\n';
}
