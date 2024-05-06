// https://codeforces.com/contest/1175/submission/259580305
void sol()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    int head = 0, tail = INF;
    for (int i = 1; i + k <= n; i++) {
        if (a[i + k] - a[i] < tail - head) {
            tail = a[i + k];
            head = a[i];
        }
    }
    cout << (tail + head) / 2 << '\n';

}
