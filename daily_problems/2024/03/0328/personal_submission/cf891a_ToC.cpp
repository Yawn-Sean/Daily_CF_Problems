/*
  https://codeforces.com/contest/891/submission/253576553
*/
void sol()
{
    cin >> n;
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (a[i] == 1) 
            cnt++;
    }
    if (cnt > 0) {
        cout << n - cnt << '\n';
        return ;
    }

    int minl = INF, g;
    for (int i = 1; i < n; i++) {
        g = a[i];
        for (int j = i + 1; j <= n; j++) {
            g = gcd(g, a[j]);
            if (g == 1) {
                minl = min(minl, j - i + 1);
            }
        }
    }
    if (minl == INF) {
        cout << -1 << '\n';
    } else {
        cout << n - 1 + minl - 1 << '\n';
    }

}
