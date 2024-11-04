Z cal(int n, int m, int u) {
    if (n + m == 1) {
        if (n == 1) return u == 0;
        return u == 1;
    }
    // 计算为1的方案数
    if (u == 0) return comb.binom(n + m, n) - cal(n, m, 1);  
    if (n == 0) return m == 1;
    Z res = 0;
    if (n - 1 >= 0) res += cal(n - 1, m, 0);
    return res;
}

void solve() {
    int n, m, g;
    cin >> n >> m >> g;
    auto t = cal(n, m, g);
    cout << t << endl;
}