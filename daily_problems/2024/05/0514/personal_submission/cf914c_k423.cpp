// https://codeforces.com/contest/914/submission/260869251

/* 我永远喜欢爱莉希雅♪ */
Mint f[1000][1001][2];
int A[1000], vis[1000][1001][2];
Mint dfs(int pos, int rem, bool is_valid, bool is_limit) {
    if (rem < 0) return 0;
    if (pos < 0) return int(is_valid && rem == 0);
    if (!is_limit && vis[pos][rem][is_valid]) return f[pos][rem][is_valid];
    vis[pos][rem][is_valid] = 1;
    Mint ret{};
    for (int x = 0; x < 2; ++x) {
        if (!is_limit || x <= A[pos]) {
            ret += dfs(pos - 1, rem - x, is_valid || x, is_limit && x == A[pos]);
        }
    }
    if (!is_limit) f[pos][rem][is_valid] = ret;
    return ret;
}

void elysia() {
    string s;
    int k;
    cin >> s >> k;
    int n = s.size();
    ranges::reverse(s);
    for (int i = 0; i < n; ++i) A[i] = s[i] - '0';
    if (k == 0) {
        cout << 1 << endl;
        return;
    }
    vector<int> h(n + 1);
    for (int i = 2; i <= n; ++i) {
        h[i] = h[__builtin_popcount(i)] + 1;
    }
    Mint ans{};
    for (int i = 1; i <= n; ++i) {
        if (h[i] == k - 1) {
            ans += dfs(n - 1, i, false, true);
        }
    }
    cout << ans - (k == 1) << endl;
}
