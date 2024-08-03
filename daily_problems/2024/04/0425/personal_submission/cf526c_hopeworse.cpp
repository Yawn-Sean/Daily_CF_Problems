void solve() {
    int c, h1, h2, b1, b2;
    cin >> c >> b1 >> b2 >> h1 >> h2;
    if (h1 < h2) {
        swap(h1, h2);
        swap(b1, b2);
    }
    int ans = -1;
    if (h1 * h1 > c) {
        for (int i = 0; i * i <= c; i++) {
            if (i * h1 > c)break;
//              sum += ((C-i*W[1])/W[2] * H[2]);
            debug(i, (c - h1 * i) / h2);

            int sums = i * b1 + (c - h1 * i) / h2 * b2;
            ans = max(ans, sums);
        }
    } else {
        if (b1 * h2 > b2 * h1) {
            swap(h1, h2);
            swap(b1, b2);
        }
        for (int i = 0; i <= max(h1, h2) * 2; i++) {
            if (c - h1 * i <= 0)break;
            int sums = i * b1 + (c - h1 * i) / h2 * b2;
            debug(i, (c - h1 * i) / h2, sums);
            ans = max(ans, sums);
        }

    }
    cout << ans << endl;
}
