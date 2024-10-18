void solve() {
    int n, m;
    cin >> n >> m;
    vec2<int> a(n, vec<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vec2<int> lt(n + 2, vec<int>(m + 2)); // (1, 1)
    vec2<int> lb(n + 2, vec<int>(m + 2)); // (n, 1)
    vec2<int> rb(n + 2, vec<int>(m + 2)); // (n, n)
    vec2<int> rt(n + 2, vec<int>(m + 2)); // (1, n)

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            chmax(lt[i][j], lt[i - 1][j] + a[i - 1][j - 1]);
            chmax(lt[i][j], lt[i][j - 1] + a[i - 1][j - 1]);
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = 1; j <= m; j++) {
            chmax(lb[i][j], lb[i + 1][j] + a[i - 1][j - 1]);
            chmax(lb[i][j], lb[i][j - 1] + a[i - 1][j - 1]);
        }
    }
    for (int i = n; i >= 1; i--) {
        for (int j = m; j >= 1; j--) {
            chmax(rb[i][j], rb[i + 1][j] + a[i - 1][j - 1]);
            chmax(rb[i][j], rb[i][j + 1] + a[i - 1][j - 1]);
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = m; j >= 1; j--) {
            chmax(rt[i][j], rt[i - 1][j] + a[i - 1][j - 1]);
            chmax(rt[i][j], rt[i][j + 1] + a[i - 1][j - 1]);
        }
    }

    int ans = 0;
    for (int i = 2; i < n; i++) {
        for (int j = 2; j < m; j++) {
            chmax(ans, lt[i - 1][j] + rb[i + 1][j] + lb[i][j - 1] + rt[i][j + 1]);
            chmax(ans, lt[i][j - 1] + rb[i][j + 1] + rt[i - 1][j] + lb[i + 1][j]);
        }
    }

    cout << ans << '\n';
}
