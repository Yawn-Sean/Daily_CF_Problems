void Solve() {
    int w, v1, v2, w1, w2;cin >> w >> v1 >> v2 >> w1 >> w2;
    int sqw = sqrt(w);
    int res = 0;
    for (int i = 0;i < sqw && w >= i * w1;i++) {
        res = max(res, i * v1 + (w - i * w1) / w2 * v2);
    }
    for (int i = 0;i < sqw && w >= i * w2;i++) {
        res = max(res, i * v2 + (w - i * w2) / w1 * v1);
    }
    cout << res << endl;
}
