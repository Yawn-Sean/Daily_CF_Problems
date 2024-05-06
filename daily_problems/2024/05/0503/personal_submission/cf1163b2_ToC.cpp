// https://codeforces.com/contest/1163/submission/259515374
int n, m;
int a[MAXN];
int v2c[MAXN];  // value to count
int c2n[MAXN];  // count to number
void sol()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int res = 1, maxc = 0;
    for (int i = 1; i <= n; i++) {
        int cur = a[i];
        c2n[v2c[cur]]--;
        v2c[cur]++;
        c2n[v2c[cur]]++;
        maxc = max(maxc, v2c[cur]);
        if (c2n[1] == 1 && (c2n[maxc] * maxc == i - 1))
            res = i;
        if (c2n[maxc] == 1 && ((maxc - 1) * (c2n[maxc - 1] + 1) == i - 1))
            res = i;
        if (c2n[1] == i)
            res = i;
        if (c2n[i] == 1)
            res = i;
    }
    cout << res << '\n';
}
