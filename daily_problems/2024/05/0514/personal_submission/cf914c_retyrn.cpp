int k;
string s;

int count(vector<bool>& need) {
    int m = s.length();
    vector<vector<int>> dp(m, vector<int>(1010, -1));

    function<int(int, int, bool, bool)> f = [&](int i, int cnt, bool is_limit, bool is_num) -> int {
        if (i == m) return is_num and need[cnt];
        if (!is_limit && is_num && dp[i][cnt] >= 0) return dp[i][cnt];
        int res = 0;
        if (!is_num) res = f(i + 1, cnt, false, false);
        for (int d = 1 - is_num, up = is_limit ? s[i] - '0' : 1; d <= up; ++d) {
            res += f(i + 1, cnt + d, is_limit && d == up, true);
            res %= mod;
        }   
        if (!is_limit && is_num) dp[i][cnt] = res;
        return res;
    };
    return f(0, 0, true, false);
}

void solve() {
    cin >> s;
    cin >> k;
    if (k == 0) {
        cout << 1 << endl;
        return;
    }
    if (k == 1) {
        cout << sz(s) - 1 << endl;
        return;
    }
    
    vector<int> f(1010, 0);
    vector<bool> need(1010, false);
    // 一次就可以变到1000以内 预处理1000以内的数需要几次
    for (int i = 2; i <= 1000; i ++) {
        f[i] = f[__builtin_popcount(i)] + 1;
        if (f[i] + 1 == k) need[i] = true;
    }
    int res = count(need);
    cout << res << endl;
}