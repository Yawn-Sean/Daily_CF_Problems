
signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int b, d;
    cin >> b >> d;

    string a, c;
    cin >> a >> c;
    int n = a.size();
    int m = c.size();

    for (int i = 0; i < n; i++)
    {
        int x = 0;
        for (int j = 0; j < 10000; j++)
        {
            if (x == m)
            {
                g[i][0] = j;
                break;
            }
            if (c[x] == a[(i + j) % n])
                x++;
        }
        if (g[i][0] == 0)
        {
            cout << 0 << "\n";
            return 0;
        }
    }

    for (int i = 1; i <= 30; i++)
    {
        for (int j = 0; j < n; j++)
        {
            g[j][i] = g[j][i - 1] + g[(j + g[j][i - 1]) % n][i - 1];
        }
    }
    int x = 0;
    int res = 0;
    int sum = b * n;
    for (int i = 30; i >= 0; i--)
    {
        if (g[x][i] <= sum)
        {
            res += 1LL << i;
            sum -= g[x][i];
            x = (x + g[x][i]) % n;
        }
    }

    cout << res / d << "\n";
    return 0;
}
