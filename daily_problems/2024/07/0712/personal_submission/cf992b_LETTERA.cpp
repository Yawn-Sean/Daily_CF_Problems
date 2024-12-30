void solve()
{
    int l, r, x, y;
    cin >> l >> r >> x >> y;
    int c = y / x;
    ll ans = 0;
    if (y % x)
    {
        debug(x);
        cout << 0 << endl;
        return;
    }
    debug((l + x - 1) / x, (int)sqrt(c) + 1);
    fo(i, (l + x - 1) / x, (int)sqrt(c) + 1)
    {

        if (i * x > r)
        {
            break;
        }
        debug(i);
        if (c % i == 0 && l <= c / i * x && c / i * x <= r && __gcd(i * x, c / i * x) == x)
        {
            debug(i, c / i);
            ans++;
            if (i != c / i)
            {
                ans++;
            }
        }
    }
    ca;
}
