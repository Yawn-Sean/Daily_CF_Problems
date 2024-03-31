int n;
int dp[1 << 8][9];
// dp[i][j] 有j个x+1 且目前的已有状态为i 的最小长度
//-----------------------function-----------------------

void solve() {
    cin >> n;
    vector<vector<int>> s(n + 1, vector<int>(8, 0));
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        x --;
        s[i] = s[i - 1];
        s[i][x] += 1;
    }

    auto get = [&](int st, int need, int u) {
        if (st >= n) return inf; 
        if (s[n][u] - s[st][u] < need) return inf;
        int l = st, r = n;
        while (l < r) {
            auto mid = (l + r) >> 1;
            if (s[mid][u] - s[st][u] < need) l = mid + 1;
            else r = mid;
        }
        return l;
    };
    
    for (int x = *min_element(all(s[n])); x > 0; x --) {
        mem(dp, 0x3f);
        dp[0][0] = 0;
        for (int i = 0; i < (1 << 8); i ++) {
            for (int j = 0; j <= (int)__builtin_popcount(i); j ++) {
                if (dp[i][j] == inf) continue;
                for (int k = 0; k < 8; k ++) {
                    if (i >> k & 1) continue;
                    auto p = get(dp[i][j], x, k);
                    dp[i | (1 << k)][j] = min(dp[i | (1 << k)][j], p);
                    if (j + 1 <= 8) {
                        p = get(dp[i][j], x + 1, k);
                        dp[i | (1 << k)][j + 1] = min(dp[i | (1 << k)][j + 1], p);
                    }
                }
            }
        }
        for (int i = 8; i >= 0; i --) {
            if (dp[(1 << 8) - 1][i] <= n) {
                cout << (x * 8 + i) << endl;
                return;
            }
        }
    }
    // x只能选0
    int res = 0;
    for (int i = 0; i < 8; i ++) {
        if (s[n][i] > 0) res ++;
    }
    cout << res << endl;
}
int main() {
    FAST;
    // Tsolve();
    solve();

    return 0;
}