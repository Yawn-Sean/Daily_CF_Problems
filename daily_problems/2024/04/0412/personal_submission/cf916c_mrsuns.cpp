int check(int x) {
    if (x == 1) return 0;
    for (int i = 2;i * i <= x;i++) {
        if (x % i == 0) return 0;
    }
    return 1;
}

void Solve(int TIME) {
    
    int n, m;cin >> n >> m;
    vi a(n + 1);
    int now = 0;
    vc<ai3> edge;for (int i = 1;i < n;i++) edge.push_back({ i,i + 1,1 });
    for (int i = 2;i <= n;i++) {
        a[i] = i - 1;
        if (i == n) while (!check(a[i])) a[i]++, edge.back().at(2)++;
    }
    m -= n - 1;
    {
        int i = 1, j = i + 2;
        while (m--) {
            edge.push_back({ i,j,a[j] - a[i] });
            if (j == n) i++, j = i + 2;
            else j++;
        }
    }

    cout << a[n] << " " << a[n] << endl;
    for (auto [u, v, w] : edge) {
        cout << u << " " << v << " " << w << endl;
    }

}

signed main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(15);
    
    PreWork();
    
    int T = 1;
    //cin >> T;
    
    int TIME = 0;
    while (T--) {
        Solve(++TIME);
    }
    
    return 0;
}
