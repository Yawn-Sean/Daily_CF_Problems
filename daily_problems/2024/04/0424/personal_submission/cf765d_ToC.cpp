// https://codeforces.com/contest/765/submission/257974433
int f[MAXN];
void sol()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> f[i];
    }
    map<int, vector<int>> Imf;
    for (int i = 1; i <= n; i++) {
        if (f[f[i]] != f[i]) {
            cout << -1 << '\n';
            return ;
        }
        Imf[f[i]].push_back(i);
    }
    int m = Imf.size();
    int idx = 1;
    vector<int> g(n + 1);
    vector<int> h(m + 1);
    for (auto &[val, vec] : Imf) {
        h[idx] = val;
        for (int i : vec)
            g[i] = idx;
        idx++;
    }
    cout << m <<'\n';
    for (int i = 1; i <= n; i++) cout << g[i] << " ";
    cout << '\n';
    for (int i = 1; i <= m; i++) cout << h[i] << " ";
    cout << '\n';

}
