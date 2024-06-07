// https://codeforces.com/contest/1561/submission/264565945
int n, m, k;
LL f[MAXN];
void sol()
{
    cin >> n >> m;
    f[1] = 1;
    LL pre = f[1];
    for (int i = 2; i <= n; i++) {
        f[i] = pre;
        LL l, r;
        for (LL l = 2; l <= i; l = r + 1) {
            r = i / (i / l);
            (f[i] += (r - l + 1) * f[i / l]) %= m;
        }
        (pre += f[i]) %= m;
    }
    cout << f[n] << '\n';
}
