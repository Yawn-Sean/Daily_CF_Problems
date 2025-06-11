LL n;

void meibao() {
    cin >> n;
    cout << "2\n";
    for (LL i = 2; i <= n; i++) {
        cout << i * i * i + 2 * i * i + 1 << "\n";
    }
}
