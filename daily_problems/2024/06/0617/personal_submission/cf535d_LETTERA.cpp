void solve()
{
    int n, m;
    cin >> n >> m;
    string s;
    cin >> s;
    int len = len(s);
    vc<int> z(len);
    int j = 0;
    for (int i = 1; i < len; i++)
    {
        z[i] = (j + z[j] <= i ? 0 : min(j + z[j] - i, z[i - j]));
        while ((i + z[i] < len) && (s[z[i]] == s[i + z[i]]))
            z[i]++;
        if (j + z[j] < i + z[i])
            j = i;
    }
    vc<int> pos(m);
    fo(i, 0, m)
    {
        cin >> pos[i];
        pos[i]--;
    }
    fo(i, 1, m)
    {
        int id = pos[i] - pos[i - 1];
        if (id < len)
        {
            if (z[id] + id != len)
            {
                cout << 0 << "\n";
                return;
            }
        }
    }
    ll ans = 1;
    const int mod = 1e9 + 7;
    vc<int> c(n + len + 5);
    fo(i, 0, m)
    {
        c[pos[i]]++;
        c[pos[i] + len]--;
    }
    fo(i, 1, n)
    {
        c[i] += c[i - 1];
    }
    fo(i, 0, n)
    {
        if (!c[i])
        {
            ans = ans * 26 % mod;
        }
    }
    ca;
}
