signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    vector<int> r(n), l(n);
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1])
        {
            r[i] = r[i + 1] + 1;
        }
    }
    for (int i = 1; i < n; i++)
    {
        if (a[i] < a[i - 1])
        {
            l[i] = l[i - 1] + 1;
        }
    }
    int lst = 0, rst = n - 1, last = -1;
    bool flag = true;
    while (true)
    {
        if (lst > rst || (a[lst] <= last && a[rst] <= last))
        {
            solve(!flag);
            break;
        }
        if (lst != rst)
        {
            if (a[lst] > a[rst])
            {
                if (r[lst] % 2 == 0)
                {
                    solve(flag);
                    break;
                }
                else
                {
                    if (a[rst] > last)
                    {
                        last = a[rst];
                        rst--;
                    }
                    else
                    {
                        solve(!flag);
                        break;
                    }
                }
            }
            else if (a[lst] < a[rst])
            {
                if (l[rst] % 2 == 0)
                {
                    solve(flag);
                    break;
                }
                else
                {
                    if (a[lst] > last)
                    {
                        last = a[lst];
                        lst++;
                    }
                    else
                    {
                        solve(!flag);
                        break;
                    }
                }
            }
            else
            {
                if (l[rst] % 2 == 0 || r[lst] % 2 == 0)
                {
                    solve(flag);
                }
                else
                {
                    solve(!flag);
                }
                break;
            }
        }
        else
        {
            solve(flag);
            break;
        }
        flag = !flag;
    }
}
