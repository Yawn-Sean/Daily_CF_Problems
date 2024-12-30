int get(char c) {
    return (c == 'R' ? 0 : (c == 'G' ? 1 : 2));
}
void solve() {
    cin >> n >> k;
    cin >> s;
    
    auto cal = [&](int st) {
        vector<vector<int>> cnt(3, vector<int>(3, 0));
        for (int i = 0; i < k; i ++) {
            int u = get(s[i]);
            int v = (i % 3 + st) % 3;
            cnt[u][v] += 1;
        }
        int res = 0;
        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j ++) {
                if (i != j) res += cnt[i][j];
            }
        }
        
        // 向后移动
        for (int i = k; i < n; i ++) {
            cnt[get(s[i - k])][st] -= 1;
            vector<vector<int>> nxt(3, vector<int>(3));
            for (int j = 0; j < 3; j ++) {
                nxt[j][0] = cnt[j][1];
                nxt[j][1] = cnt[j][2];
                nxt[j][2] = cnt[j][0];
            }
            nxt[get(s[i])][((k - 1) % 3 + st) % 3] += 1;
            int ans = 0;
            for (int j = 0; j < 3; j ++) {
                for (int t = 0; t < 3; t ++) {
                    if (j != t) ans += nxt[j][t];
                }
            }
            res = min(res, ans);
            cnt = move(nxt);
        }
        return res;
    };
    
    int res = k;
    for (int i = 0; i < 3; i ++) {
        res = min(res, cal(i));
    }
    cout << res << endl;
}