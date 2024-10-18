void Solve() {
    int n;cin >> n;
    vector<int> a(2 * n + 1);
    int pos;
    for (int i = 1, j = n, p = 1;i < j;i++, j--, p += 2) {
        a[i] = a[j] = p;
    }
    for (int i = n + 1, j = 2 * n - 1, p = 2;i < j;i++, j--, p += 2) {
        a[i] = a[j] = p;
    }
    for (int i = 1;i <= 2 * n;i++) {
        if (a[i] == 0) a[i] = n;
    }
    for (int i = 1;i <= 2 * n;i++) {
        cout << a[i] << " ";
    }
    cout << endl;

}
