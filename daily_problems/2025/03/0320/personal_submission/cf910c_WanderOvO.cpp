/*
10! 不超过 4e6
能否先不进位，把表达式用 a-j 算出来，然后枚举 10!，再计算表达式呢
woc 一位数也不能是 0
*/

int n;
LL cnt[7][11];
LL power[7], p[11];
bool vis[11];
LL res = INFLL;
bool not_zero[11];

void dfs(int u) {
    if (u == 10) {
        for (int i = 0; i < 10; i++) {
            if (p[i] == 0 && not_zero[i]) {
                return;
            }
        }
        LL ans = 0;
        for (int i = 0; i < 7; i++) {
            for (int j = 0; j < 10; j++) {
                ans += cnt[i][j] * power[i] * p[j];
            }
        }
        res = min(res, ans);
        return;
    }

    for (int i = 0; i < 10; i++) {
        if (!vis[i]) {
            vis[i] = true;
            p[u] = i;
            dfs(u + 1);
            vis[i] = false;
        }
    }
}

void meibao() {
    cin >> n;
    string s;
    for (int i = 1; i <= n; i++) {
        cin >> s;
        reverse(s.begin(), s.end());
        for (int j = 0; j < s.size(); j++) {
            cnt[j][s[j] - 'a']++;
        }
        not_zero[s.back() - 'a'] = true;
    }
    power[0] = 1;
    for (int i = 1; i < 7; i++) {
        power[i] = power[i - 1] * 10;
    }

    dfs(0);

    cout << res << "\n";
}   
