// https://codeforces.com/contest/573/submission/258517499
int h[MAXN], res[MAXN];
void sol()
{
    cin >> n;
    
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    int cur = 0;
    for (int i = 1; i <= n; i++) {
        cur = min(cur, h[i] - i);
        res[i] = cur + i;
    }
    cur = n + 1;
    for (int i = n; i >= 1; i--) {
        cur = min(cur, h[i] + i);
        res[i] = min(res[i], cur - i);
    }
    int k = -1;
    for (int i = 1; i <= n; i++)
        k = max(k, res[i]);
    cout << k << '\n';    
}
