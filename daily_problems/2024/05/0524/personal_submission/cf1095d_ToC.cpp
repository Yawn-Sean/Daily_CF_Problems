// https://codeforces.com/contest/1095/submission/262356734
int n, m;
vector<int> g[MAXN];
void sol()
{
    cin >> n;
    int x, y;
    for (int i = 1; i <= n; i++) {
        cin >> x >> y;
        g[i].push_back(x);
        g[i].push_back(y);
    }
    if (n == 3) {
        for (int i = 1; i <= n; i++)
            cout << i << " ";
        cout << '\n';
        return ;
    }
    vector<int> cir {1};
    int a = 1, b, c;
    while (cir.size() < n) {
        b = g[a][0], c = g[a][1];
        if (c == g[b][0] || c == g[b][1]) {
            cir.push_back(b);
            cir.push_back(c);
            a = c;
        } else {
            cir.push_back(c);
            cir.push_back(b);
            a = b;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << cir[i];
        if (i < n - 1) cout << " ";
    }
    cout << '\n';
}
