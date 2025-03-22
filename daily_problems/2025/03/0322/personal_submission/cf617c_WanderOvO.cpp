PLL ps[N], s1, s2;
PLL d[N];
int n;
LL mx[N];

LL get_dist(PLL a, PLL b) {
    return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y);
}

void meibao() {
    cin >> n >> s1.x >> s1.y >> s2.x >> s2.y;
    for (int i = 1; i <= n; i++) {
        cin >> ps[i].x >> ps[i].y;
        d[i].x = get_dist(ps[i], s1);
        d[i].y = get_dist(ps[i], s2);
    }

    sort(d + 1, d + n + 1);
    mx[n + 1] = 0;
    mx[n] = d[n].y;
    for (int i = n - 1; i > 0; i--) {
        mx[i] = max(mx[i + 1], d[i].y);
    }

    LL res = INFLL;
    for (int i = 0; i <= n; i++) {
        res = min(res, d[i].x + mx[i + 1]);
    }
    cout << res << "\n";
}
