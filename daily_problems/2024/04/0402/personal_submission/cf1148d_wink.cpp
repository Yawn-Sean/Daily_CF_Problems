
void solve()
{
    int n;
    cin >> n;
    vector<array<int, 3>> a, b;
    for (int i = 0; i < n; ++i)
    {
        int x, y;
        cin >> x >> y;
        if (x < y)
            a.push_back({x, y, i + 1});
        else
        {
            b.push_back({x, y, i + 1});
        }
    }
    sort(a.begin(), a.end(), [](const array<int, 3> &i, const array<int, 3> &j)
         { return i[1] > j[1]; });
    sort(b.begin(), b.end(), [](const array<int, 3> &i, const array<int, 3> &j)
         { return i[1] < j[1]; });

    cout << max(sz(a), sz(b)) << '\n';
    if (sz(a) > sz(b))
    {

        for (int i = 0; i < sz(a); ++i)
        {
            cout << a[i][2] << " ";
        }
    }
    else
    {
        for (int i = 0; i < sz(b); ++i)
        {
            cout << b[i][2] << " ";
        }
    }
}
