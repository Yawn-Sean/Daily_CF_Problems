C_prime<1000000> C;
 
void solve() {
    int n, m, g;
    cin >> n >> m >> g;
    mint ans = 0;
    if (m == 0) {
        if (n % 2 == 0 && g == 1) {
            ans = 1;
        } else if (n % 2 == 1 && g == 0) {
            ans = 1;
        }
    } if (n == 0) {
        if (g == 0 && m != 1) {
            ans = 1;
        }
        if (g == 1 && m == 1) {
            ans = 1;
        }
    } else {
        int len = n + m;
        if (g == 0) {
            ans += C(len - 1, m - 1);
        }
        for (int i = 1; i <= n; i++) {
            int res;
            if (i == n && m == 1) {
                res = (i % 2 == 0);
            } else {
                res = ((i + 1) % 2 == 0);
            }
            if (res == g) {
                ans += C(len - i - 1, m - 1);
            }
        }
    }
    cout << ans.v << "\n";
}
 
