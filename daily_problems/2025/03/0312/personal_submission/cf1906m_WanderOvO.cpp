LL n, a[N];

void meibao() {
    cin >> n;
    LL sum = 0, mx = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        sum += a[i];
        mx = max(mx, a[i]);
    }

    cout << min(sum / 3, sum - mx) << "\n";
}
