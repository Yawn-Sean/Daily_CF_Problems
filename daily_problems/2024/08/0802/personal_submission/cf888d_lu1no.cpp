LL n, k;
LL C[N][N], A[N][N], f[N];
 
// 伯努利错装信封问题
// f(n) = (n - 1) * (f(n - 1) + f(n - 2)) n >= 3
// f(1) = 0, f(2) = 1
void init() {
    for (int n = 0; n < N; n ++) {
        for (int m = 0; m <= n; m ++) {
            if (!m) C[n][m] = 1;
            else C[n][m] = C[n - 1][m] + C[n - 1][m - 1];
        }
    }
    A[0][0] = 1;
    for (int k = 1; k <= 5; k ++) {
        A[k][k] = 1;
        for (int i = 1; i <= k; i ++) A[k][k] *= i;
    }
    f[1] = 0, f[2] = 1;
    for (int i = 3; i <= 20; i ++) {
        f[i] = (i - 1) * (f[i - 1] + f[i - 2]);
    }
}
 
 
void solve() {
    cin >> n >> k;
    LL ans = 1;
    for (; k >= 1; k --) {
        ans += C[n][k] * f[k];
    }
    cout << ans << endl;
}
