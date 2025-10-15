LL n, x[N], y[N];

int gcd(int a, int b) {
    return b == 0 ? a : gcd(b, a % b);
}

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> x[i] >> y[i];
    }

    LL res = n * (n - 1) * (n - 2) / 6;

    for (int i = 1; i <= n; i++) {
        map<PII, LL> cnt;
        for (int j = i + 1; j <= n; j++) {
            int xx = x[j] - x[i], yy = y[j] - y[i];
            int g = gcd(xx, yy);
            assert(g != 0);
            xx /= g;
            yy /= g;
            if (xx < 0 && yy < 0) {
                xx = -xx;
                yy = -yy;
            } else if (xx < 0) {
                xx = -xx;
                yy = -yy;
            } 
            cnt[{xx, yy}]++;
        }
        for (auto &it : cnt) {
            if (it.y >= 2) {
                res -= it.y * (it.y - 1) / 2;
            }
        }
    }
    cout << res << "\n";
}  
