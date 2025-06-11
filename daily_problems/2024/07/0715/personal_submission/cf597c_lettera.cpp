void solve()
{

    int n, k;
    cin >> n >> k;
    vc<int> a(n);
    ll ans = 0;
    fo(i, 0, n)
    {
        cin >> a[i];
    }
    vc<ll> f(n, 1);
    fo(_, 0, k)
    {
        init();
        fo(i, 0, n)
        {
            add(a[i], f[i]);
            f[i] = getsum(a[i] - 1);
        }
    }
    fo(i, 0, n)
    {
        ans += f[i];
    }
    ca;
}
