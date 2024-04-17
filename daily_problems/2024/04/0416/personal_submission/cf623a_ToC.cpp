// https://codeforces.com/contest/623/submission/256881467
int n, t, m, a, b;
int g[MAXN][MAXN];
int deg[MAXN];
bool vis[MAXN];
vector<int> cc_start;
vector<vector<int>> cc_node;
vector<int> Ch[3];
void dfs1(int i, vector<int> &cur) {
    vis[i] = true;
    cur.push_back(i);
    for (int nb = 1; nb <= n; nb++) {
        if (g[i][nb] == 1 && !vis[nb]) { 
            dfs1(nb, cur);
        }
    }
}
void dfs2(int i, vector<int> &cur) {
    vis[i] = true;
    cur.push_back(i);
    for (int j = 1; j <= n; j++) {
        if (g[i][j] == 1 && deg[j] != n - 1 && !vis[j])
            dfs2(j, cur);
    }
}
void sol()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> a >> b;
        g[a][b] = g[b][a] = 1;
        deg[a]++;
        deg[b]++;
    }
    
    for (int i = 1; i <= n; i++) {
        if (!vis[i]) {
            cc_start.push_back(i);
            cc_node.emplace_back(vector<int>());
            dfs1(i, cc_node.back());
        }
    }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (deg[i] == n - 1){
            cnt++;
            Ch[1].push_back(i);
        }

    int cc_siz = cc_start.size();

    if (cc_siz == 1) {
        if (cnt == 0) {
            cout << "NO\n";
        } else if (cnt == n) {
            cout << "YES\n";
            for (int i = 1; i <= n; i++)
                cout << "a";
            cout << '\n';
        } else {
            for (int i = 1; i <= n; i++)
                if (deg[i] != n - 1)
                    a = i;
            memset(vis, false, sizeof(vis));
            dfs2(a, Ch[0]);

            memset(vis, false, sizeof(vis));
            bool ok = true;
            for (auto &a : Ch[0]) {
                vis[a] = true;
                if (deg[a] != (Ch[1].size() + Ch[0].size() - 1))
                    ok = false;
            }
            for (auto &b : Ch[1])
                vis[b] = true;
            for (int i = 1; i <= n; i++)
                if (!vis[i])
                    Ch[2].push_back(i);
            for (auto &c : Ch[2]) {
                if (deg[c] != (Ch[1].size() + Ch[2].size() - 1))
                    ok = false;
            }

            if (!ok) {
            cout << "NO\n";
            } else {
                cout <<"YES\n";

                char res[n + 1];
                for (auto &a : Ch[0])
                    res[a] = 'a';
                for (auto &c : Ch[2])
                    res[c] = 'c';
                for (auto &b : Ch[1])
                    res[b] = 'b';
                for (int i = 1; i <= n; i++)
                    cout << res[i];
                cout << '\n';
            }

        }
    } else if (cc_siz == 2) {
        int s1 = cc_node[0].size(), s2 = cc_node[1].size();
        bool ok = true;
        for (auto & a : cc_node[0])
            if (deg[a] != s1 - 1)
                ok = false;
        for (auto & c : cc_node[1])
            if (deg[c] != s2 - 1)
                ok = false;
        if (!ok) {
            cout << "NO\n";
        } else {
            cout <<"YES\n";
            char res[n + 1];
            for (auto &a : cc_node[0])
                res[a] = 'a';
            for (auto &c : cc_node[1])
                res[c] = 'c';
            for (int i = 1; i <= n; i++)
                cout << res[i];
            cout << '\n';
        }
    } else {
        cout << "NO\n";
    }
}
