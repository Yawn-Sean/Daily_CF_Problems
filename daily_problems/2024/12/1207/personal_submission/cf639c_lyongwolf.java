static void solve() {
    int n = sc.nextInt(), k = sc.nextInt();
    long[] a = new long[n + 1];
    for (int i = 0; i <= n; i++) {
        a[i] = sc.nextLong();
    }
    long[] b = new long[n + 1];
    long p = 0;
    for (int i = 0; i <= n; i++) {
        long t = (p + a[i]);
        b[i] = i < n ? t % 2 : t;
        p = t / 2;
    }
    int l = 0;
    while (l <= n && b[l] == 0) {
        l++;
    }
    int cnt = 0;
    p = 0;
    for (int i = n; i >= 0; i--) {
        p = p * 2 + b[i];
        if (abs(p) > k * 2) {
            break;
        }
        if (i <= l) {
            long t = abs(p - a[i]);
            if (t <= k && (i < n || t != 0)) {
                cnt++;
            }
        }
    }
    out.println(cnt);
}
