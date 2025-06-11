
void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    vector<int> check(n + 1, -1);
    int ans = 0;
    vector<int> factor;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) factor.emplace_back(i);
    }
    for (int f : factor) {
        if (check[gcd(f, n)] == -1) {
            bool okay = true;
            vector<int> vis(n);
            for (int i = 0; i < n; i++) {
                if (vis[i]) {
                    continue;
                }
                vis[i] = 1;
                int val = s[i] - '0', nextPos = (i + f) % n;
                while (!vis[nextPos]) {
                    vis[nextPos] = 1;
                    val ^= (s[nextPos] - '0');
                    nextPos = (nextPos + f) % n;
                }
                if (val) {
                    okay = false;
                    break;
                } 
            }
            if (okay) {
                check[gcd(n, f)] = 1;
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (check[gcd(n, i)] == 1) ans++;
    }
    cout << ans;
}
