// https://codeforces.com/contest/1033/submission/266809359
int i2v[MAXN], v2i[MAXN];
int res[MAXN];
void sol()
{
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> i2v[i];
        v2i[i2v[i]] = i;
    }
    res[v2i[1]] = 1;    //必胜
    res[v2i[n]] = 0;    //必败
    for (int v = n - 1; v >= 2; v--) {
        int tms = n / v;    //[1, n]中有tms个v的倍数，1倍，2倍，...，tms倍
        int idx = v2i[v];   //idx是v的下标
        bool win = false;
        for (int j = 1; j <= tms; j++) {
            int i1 = idx - v * j, i2 = idx + v * j;
            if (i1 >= 1 && i1 <= n && i2v[i1] > v) {
                if (res[i1] == 0) {
                    win = true;
                }
            }
            if (i2 >= 1 && i2 <= n && i2v[i2] > v) {
                if (res[i2] == 0) {
                    win = true;
                }
            }
        }
        if (win) res[idx] = 1;
        else res[idx] = 0;
    }
    for (int i = 1; i <= n; i++) {
        if (res[i]) cout << "A";
        else cout << "B";
    }
    cout << '\n';
}
