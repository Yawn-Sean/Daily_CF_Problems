int n;
PDD res[N];

void meibao() {
    cin >> n;
    if (n <= 4) {
        cout << "No solution\n";
        return;
    }

    res[1].x = 0;
    res[1].y = 0;
    double pi = acos(-1);
    // double delta = pi - ((n - 2) * pi) / n;
    double delta = 2 * pi / n;
    double e = 0.01, l = 300, cur = pi + delta;
    for (int i = 2; i < n; i++) {
        double dx = l * cos(cur), dy = l * sin(cur);
        res[i] = {res[i - 1].x + dx, res[i - 1].y + dy};
        l += e;
        cur += delta;
    }

    res[n].y = 0;
    // 过 (res[n - 1].x, res[n - 1].y)，斜率为 tan(cur) 的直线
    // y - res[n - 1].y = k * (x - res[n - 1].x)
    // x = -res[n - 1].y / k + res[n - 1].x
    res[n].x = -res[n - 1].y / tan(cur) + res[n - 1].x;
    for (int i = 1; i <= n; i++) {
        cout << setprecision(15) << res[i].x << " " << res[i].y << "\n";
    }
}
