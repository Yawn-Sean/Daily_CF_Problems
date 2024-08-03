int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    int prime = 998244353;

    cout << prime << " " << prime << endl;
    for (int i = 1; i < n - 1; ++i)
    {
        cout << i << " " << i + 1 << " 1" << endl;
    }
    cout << n - 1 << " " << n << " " << prime - (n - 2) << endl;

    m -= n - 1;
    for (int j = 0; j < n; ++j)
    {
        if (m == 0)
            break;
        for (int i = 0; i < j - 1; ++i)
        {
            if (m == 0)
                break;
            cout << i + 1 << " " << j + 1 << " " << 1000000000 << std::endl;
            m -= 1;
        }
    }
    return 0;
}
