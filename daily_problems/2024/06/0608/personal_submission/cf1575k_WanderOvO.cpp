int T;
LL n, m, k, r, c;

void solve1() {
    cin >> n >> m >> k >> r >> c;
    LL ax, ay, bx, by;
    cin >> ax >> ay >> bx >> by;
    cout << qpow(k, n * m - r * c * ((ax == bx && ay == by) ? 0 : 1), MOD1);
}           