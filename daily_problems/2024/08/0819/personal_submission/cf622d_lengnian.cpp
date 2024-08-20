signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, x, y;
    cin >> n;

    vector<int> arr(2 * n, 0);

    for (int i = 0; i < 2 * n; i++)
    {
        arr[i] = n;
    }

    for (int i = 1; i < n; i++)
    {
        if (i & 1)
        {
            x = i >> 1;
        }
        else
        {
            x = n - 1 + (i >> 1);
        }
        y = x + (n - i);
        arr[x] = arr[y] = i;
    }

    for (int i = 0; i < 2 * n; i++)
    {
        cout << arr[i] << ' ';
    }
    return 0;
}
