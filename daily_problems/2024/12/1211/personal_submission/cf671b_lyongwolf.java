void solve() {
    int n = sc.nextInt(), k = sc.nextInt();
    int[] a = new int[n];
    for (int i = 0; i < n; i++) {
        a[i] = sc.nextInt();
    }
    if (n == 1) {
        out.println(0);
        return;
    }
    Arrays.sort(a);
    if (k == 0) {
        out.println(a[n - 1] - a[0]);
        return;
    }
    long[] sum = new long[n + 1];
    for (int i = 0; i < n; i++) {
        sum[i + 1] = sum[i] + a[i];
    }
    long l = 1, r = a[n - 1], m;
    while (l <= r) {
        m = (l + r) >> 1;
        long need = 0;
        for (int i = 0; i < n; i++) {
            if (a[i] >= m) {
                break;
            }
            need += m - a[i];
        }
        if (need <= k) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    long low = l - 1;
    l = 1;
    r = a[n - 1];
    while (l <= r) {
        m = (l + r) >> 1;
        long need = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] <= m) {
                break;
            }
            need += a[i] - m;
        }
        if (need <= k) {
            r = m - 1;
        } else {
            l = m + 1;
        }
    }
    long high = r + 1;
    if (low >= high) {
        out.println(sum[n] % n == 0 ? 0 : 1);
        return;
    }
    out.println(high - low);
}
