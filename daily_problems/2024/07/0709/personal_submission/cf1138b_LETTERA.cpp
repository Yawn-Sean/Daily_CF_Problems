void solve()
{
    int n;
    cin >> n;
    string a, b;
    cin >> a >> b;
    int cnt = 0;
    vv(int, f, 3);
    fo(i, 0, n)
    {
        cnt += a[i] == '1';
        f[a[i] - '0' + b[i] - '0'].pb(i + 1);
    }
    fo(i, 0, len(f[2]) + 1)
    {
        int j = cnt - 2 * i;
        int k = n / 2 - i - j;
        if (j >= 0 && j <= len(f[1]) && k >= 0 && k <= len(f[0]))
        {
            fo(id, i, len(f[2]))
            {
                cout << f[2][id] << " ";
            }
            fo(id, j, len(f[1]))
            {
                cout << f[1][id] << " ";
            }
            fo(id, k, len(f[0]))
            {
                cout << f[0][id] << " ";
            }
            return;
        }
    }
    cout << -1 << "\n";
}
