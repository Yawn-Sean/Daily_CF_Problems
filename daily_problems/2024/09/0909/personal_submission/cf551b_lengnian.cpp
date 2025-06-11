signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    string a, b, c;
    cin >> a >> b >> c;

    vector<int> x(26, 0), y(26, 0), z(26, 0);

    for (int i = 0; i < a.size(); i++)
        x[a[i] - 'a']++;
    for (int i = 0; i < b.size(); i++)
        y[b[i] - 'a']++;
    for (int i = 0; i < c.size(); i++)
        z[c[i] - 'a']++;

    i64 pos = LLONG_MAX, ios = LLONG_MAX, m = 0, n = 0;
    for (int i = 0; i < 26; i++)
        if (y[i])
            pos = min(pos, x[i] / y[i]);
    for (int i = 0; i <= pos; i++)
    {
        for (int j = 0; j < 26; j++)
            if (z[j])
                ios = min(ios, (x[j] - y[j] * i) / z[j]);
        if (i + ios > m + n)
            m = i, n = ios;
    }
    for (int i = 0; i < 26; i++)
        for (int j = x[i] - m * y[i] - n * z[i]; j > 0; j--)
            cout << char('a' + i);
    while (m--)
        cout << b;
    while (n--)
        cout << c;
    return 0;
}
