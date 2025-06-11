signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    string a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        for (int j = 0; j < (int)a[i].size(); j++)
        {
            int cur = 0;
            for (int k = j; k < (int)a[i].size(); k++)
            {
                cur = cur * 11 + (a[i][k] - '0' + 1);
                use[cur]++;
            }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (int)a[i].size(); j++)
        {
            int cur = 0;
            for (int k = j; k < a[i].size(); k++)
            {
                cur = cur * 11 + (a[i][k] - '0' + 1);
                use[cur]--;
            }
        }
        string ans = string(15, '1');
        for (int j = 0; j < a[i].size(); j++)
        {
            int cur = 0;
            for (int k = j; k < a[i].size(); k++)
            {
                cur = cur * 11 + (a[i][k] - '0' + 1);
                if (!use[cur])
                {
                    if (k - j + 1 < ans.size())
                    {
                        ans = a[i].substr(j, k - j + 1);
                    }
                }
            }
        }
        for (int j = 0; j < a[i].size(); j++)
        {
            int cur = 0;
            for (int k = j; k < a[i].size(); k++)
            {
                cur = cur * 11 + (a[i][k] - '0' + 1);
                use[cur]++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
