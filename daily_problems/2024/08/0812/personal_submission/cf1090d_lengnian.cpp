signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        e[u].insert(v);
        e[v].insert(u);
    }

    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            if (i != j)
            {
                if (!e[i].count(j))
                {
                    cout << "YES" << "\n";
                    int tot = 0;
                    for (int k = 1; k < n + 1; k++)
                    {
                        if (i != k && j != k)
                        {
                            tot++;
                            a[k] = tot;
                            b[k] = tot;
                        }
                    }

                    a[i] = tot + 1;
                    a[j] = tot + 2;
                    b[i] = tot + 1;
                    b[j] = tot + 1;
                    for (int k = 1; k < n + 1; k++)
                    {
                        cout << a[k] << " ";
                    }
                    cout << "\n";
                    for (int k = 1; k < n + 1; k++)
                    {
                        cout << b[k] << " ";
                    }
                    cout << "\n";
                    return 0;
                }
            }
        }
    }

    cout << "NO" << "\n";
}
