LL mx[N], s[N], x[N], n;

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> s[i] >> x[i];
    }

    mx[1] = s[1] + x[1];
    for (int i = 2; i <= n; i++) {
        mx[i] = s[i] + x[i];
        mx[i] = min(mx[i], mx[i - 1] + 1);
    }

    LL res = mx[n] - s[n];
    if (mx[n] < s[n] || mx[n] > s[n] + x[n]) {
        cout << "-1\n";
        return;
    }
    for (int i = n - 1; i > 0; i--) {
        mx[i] = min(mx[i], mx[i + 1] + 1);
        if (mx[i] < s[i] || mx[i] > s[i] + x[i]) {
            cout << "-1\n";
            return;
        }
        res += mx[i] - s[i];
    }
    cout << res << "\n";
    for (int i = 1; i <= n; i++) {
        cout << mx[i] << " ";
    }
}
