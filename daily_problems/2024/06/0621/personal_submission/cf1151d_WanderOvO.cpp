/*
最小化 sum(a[i] * (j - 1) + b[i] * (n - j))
sum((a[i] - b[i]) * j - a[i] + n * b[i]), j = 1, 2, ... n
根据排序不等式，只要求反序和即可
*/

int T;
LL n;
PLL a[N];

bool cmp(const PLL &o1, const PLL &o2) {
    return (o1.x - o1.y) > (o2.x - o2.y);
}

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].y;
    }
    sort(a + 1, a + n + 1, cmp);
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        res += (a[i].x - a[i].y) * i - a[i].x + n * a[i].y;
    }
    cout << res << "\n";
}      