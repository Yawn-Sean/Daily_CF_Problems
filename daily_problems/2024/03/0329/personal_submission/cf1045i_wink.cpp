void solve()
{
    int n;
    cin >> n;

    ll ans = 0;
    map<int, int> cnt;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        int v = 0;
        for (auto c : s)
        {
            int x = c - 'a';
            v ^= (1 << x);
        }
        for (int i = 0; i < 26; ++i)
        {
            ans += cnt[v ^ (1 << i)];
        }
        ans += cnt[v];
        cnt[v]++;
    }

    cout << ans << '\n';
}
