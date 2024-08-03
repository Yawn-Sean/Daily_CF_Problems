void solve() {
    int n, k;
    std::cin >> n >> k;
    vi a(n), b(k), idx_a(n + 1), idx_b(n + 1, -1);
    rep (i, 0, n) {
        std::cin >> a[i];
        idx_a[a[i]] = i;
    }
    rep (i, 0, k) {
        std::cin >> b[i];
        idx_b[b[i]] = i;
    }
    int m = 0;
    for (int x: b) {
        int iax = idx_a[x], ibx = idx_b[x];
        // 可行性
        if (iax == 0   and idx_b[a[1]] > ibx or 
            iax == n-1 and idx_b[a[n-2]] > ibx or
            iax > 0 and iax < n - 1 and idx_b[a[iax + 1]] > ibx and idx_b[a[iax - 1]] > ibx) {
            cout << 0 << nl;
            return ;
        }
        // 计数
        if (iax != 0 and iax != n-1 and idx_b[a[iax-1]] < ibx and idx_b[a[iax+1]] < ibx) m++;
    }
    // 更简单的判断写法
    // for (int x: b) {
    //     iax = idx_a[x], ibx = idx_b[x];
    //     c = 0;
    //     if (iax > 0 and idx_b[a[iax - 1]] < ibx) c++;
    //     if (iax < n - 1 and idx_b[a[iax + 1]] < ibx) c++;
    //     if (!c) return cout << 0 << nl, void();
    //     m += (c == 2);
    // }
    std::cout << ksm(2, m, mod) << nl;
}
