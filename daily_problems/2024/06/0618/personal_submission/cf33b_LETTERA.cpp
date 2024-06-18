void solve()
{
    string a, b;
    cin >> a >> b;
    if (len(a) != len(b))
    {
        cout << -1 << "\n";
        return;
    }
    int m;
    cin >> m;
    vc<vc<int>> dis(26, vc<int>(26, 2505));
    while (m--)
    {
        char x, y;
        cin >> x >> y;
        int w;
        cin >> w;
        int u = x - 'a', v = y - 'a';
        dis[u][v] = min(dis[u][v], w);
    }
    fo(i, 0, 26)
    {
        dis[i][i] = 0;
    }
    for (int k = 0; k < 26; k++)
    {
        fo(i, 0, 26)
        {
            fo(j, 0, 26)
            {
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
 
    int cnt = 0;
    string ans;
    fo(i, 0, len(a))
    {
        int u = a[i] - 'a', v = b[i] - 'a';
        int ok = 0;
        fo(i, 0, 26)
        {
            if (dis[u][i] + dis[v][i] < 2505)
            {
                ok = 1;
            }
        }
        if (!ok)
        {
 
            cout << -1 << "\n";
            return;
        }
        else
        {
            int id = 0, t = 2505;
            fo(i, 0, 26)
            {
                if (dis[u][i] + dis[v][i] < t)
                {
                    id = i;
                    t = dis[u][i] + dis[v][i];
                }
            }
            cnt += dis[u][id] + dis[v][id];
            ans += id + 'a';
        }
    }
    cout << cnt << "\n";
    cout << ans;
}
