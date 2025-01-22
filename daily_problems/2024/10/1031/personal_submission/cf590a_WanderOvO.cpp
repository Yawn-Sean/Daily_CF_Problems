int n;
int a[N], res = 0;

void op(int l, int r) {
    res = max(res, (r - l - 1) / 2);
    for (int i = l; i < (l + r) / 2; i++) {
        a[i] = a[l];
    }
    for (int i = (l + r) / 2; i < r; i++) {
        a[i] = a[r - 1];
    }
}

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    int l = 1;
    for (int i = 2; i <= n; i++) {
        if (a[i] == a[i - 1]) {
            op(l, i);
            l = i;
        }
    }
    op(l, n + 1);
    cout << res << "\n";
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
}
