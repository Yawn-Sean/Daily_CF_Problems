// https://codeforces.com/contest/33/submission/266630927
string s1, s2;
vector<vector<int>> g(26, vector<int>(26, INF));
void sol()
{
    cin >> s1 >> s2;
    if (s1.size() != s2.size()) {
        cout << -1 << '\n';
        return ;
    }
    cin >> n;
    char a, b;
    int w;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b >> w;
        int s = a - 'a', t = b - 'a';
        g[s][t] = min(g[s][t], w); 
    }

    for (int i = 0; i < 26; i++) 
        g[i][i] = 0;

    for (int k = 0; k < 26; k++) {
        for (int i = 0; i < 26; i++) {
            for (int j = 0; j < 26; j++) {
                if (g[i][k] != INF && g[k][j] != INF)
                    g[i][j] = min(g[i][j], g[i][k] + g[k][j]);
            }
        }
    }
    int res = 0;    
    for (int i = 0; i < s1.size(); i++) {
        if (s1[i] != s2[i]) {
            int a = s1[i] - 'a', b = s2[i] - 'a', tmp = -1;
            bool f1 = g[a][b] != INF, f2 = g[b][a] != INF, f3 = false;
            for (int i = 0; i < 26; i++) {
                if (g[a][i] != INF && g[b][i] != INF && i != a && i != b)
                    f3 = true;
            }
            int v1 = INF, v2 = INF, v3 = INF, minv = INF;
            char c = '?';
            if (f1) v1 = g[a][b];
            if (f2) v2 = g[b][a];
            if (f3) {
                for (int i = 0; i < 26; i++) {
                    if (g[a][i] != INF && g[b][i] != INF && a != i && b != i) {
                        if (v3 == INF || v3 > g[a][i] + g[b][i]) {
                            v3 = g[a][i] + g[b][i];
                            c = i + 'a';
                        }
                    }
                }
            }
            minv = min({v1, v2, v3});
            if (minv == INF) {
                res = -1;
                break;
            } else {
                if (minv == v1) {
                    s1[i] = b + 'a';
                    tmp = v1;
                } 
                if (minv == v2) {
                    tmp = v2;
                } 
                if (minv == v3) {
                    s1[i] = c;
                    tmp = v3;
                }
            }
            res += tmp;
        }   
    }
    cout << res << '\n';
    if (res != -1) cout << s1 << '\n';
}
