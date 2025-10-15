// ٩ (◕‿◕�?) ۶
    vector<int> vis(123, 0), flag(1000, 0);
    string s;
    char q;
    int n, ans = 0;
    bool dian = false;
    cin >> n;
    for (int i = 1; i < n; i++)
    {
        cin >> q >> s;
        if (dian) {
            if (q != '.')
                ans++;
            continue;
        }
        if (q == '!') {
            fill(all(vis), 0);
            for (int j = 0; j < s.length(); j++) {
                vis[s[j]] = true;
                flag[s[j]] = flag[s[j]] != -1 ? 1 : flag[s[j]];
            }
            for (char j = 'a'; j <= 'z'; j++)
                if (!vis[j])
                    flag[j] = -1;
        }
        else if (q == '.')
            for (int j = 0; j < s.length(); j++)
                flag[s[j]] = -1;
        else
            flag[s[0]] = -1;
        int cnt = 0, f = 0;
        for (char j = 'a'; j <= 'z'; j++) {
            if (flag[j] == 1)
                cnt++;
            else if (flag[j] == -1)
                f++;
        }
        if (cnt == 1 || f == 25) { //验证是否只剩一个
            dian = true;
        }
    }
    cout << ans;



