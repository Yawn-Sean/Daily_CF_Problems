void solve()
{
    double ax, ay, bx, by, tx, ty, x, y;
    cin >> ax >> ay >> bx >> by >> tx >> ty;

    function<double(void)> f1 = [&]()
    {
        return hypot(x - ax, y - ay);
    };

    function<double(void)> f2 = [&]()
    {
        return hypot(x - bx, y - by);
    };

    function<double(void)> f = [&]()
    {
        return hypot(x - tx, y - ty);
    };
    int n;
    cin >> n;
    double ans = 0, t1 = 4e9, t2 = 4e9, t3 = 4e9;
    while (n--)
    {

        cin >> x >> y;
        double d1 = f1(), d2 = f2(), d = f();
        ans += 2 * d;
        t3 = min({t3, t1 + d2 - d, t2 + d1 - d});
        t1 = min(t1, d1 - d);
        t2 = min(t2, d2 - d);
    }
    ans += min({t1, t2, t3});
    cout << setprecision(15) << ans << "\n";
}
