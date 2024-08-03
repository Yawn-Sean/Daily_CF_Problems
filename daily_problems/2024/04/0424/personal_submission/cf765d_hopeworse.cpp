void solve() {
    int n;
    cin >> n;
    int tot = 0;
    vector<int> g(n + 1), h(n + 1);

    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        if (!g[x]) g[x] = ++tot, h[tot] = x, g[i] = tot;
        else if (h[g[x]] == x) g[i] = g[x];
        else {
            cout << -1;
            return;
        }
    }
    cout << tot << endl;
    for (int i = 1; i <= n; i++) {
        cout << g[i] << " \n"[i == n];
    }
    for(int i = 1;i<=tot;i++)  cout << h[i] << " \n"[i == tot];
}
