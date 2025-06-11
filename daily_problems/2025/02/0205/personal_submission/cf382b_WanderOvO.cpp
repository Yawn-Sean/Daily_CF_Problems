LL a, b, w, x, c;

void meibao() {
    cin >> a >> b >> w >> x >> c;
    if (c <= a) {
        cout << "0\n";
        return;
    }
    cout << ((c - a) * w - b + w - x - 1) / (w - x) << "\n";
}
