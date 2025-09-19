string s, t;
int n;

void meibao() {
    cin >> s;
    n = s.size();
    s = " " + s;
    t = "cdhs";
    int res = 0;
    while (true) {
        // cout << t << endl;
        vector<int> dp(4, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 0; j < 4; j++) {
                if (s[i] == t[j]) {
                    dp[j]++;
                }
            }
            for (int j = 1; j < 4; j++) {
                dp[j] = max(dp[j], dp[j - 1]);
            }
        }

        res = max(res, dp[3]);
        // cout << res << endl;

        if (!next_permutation(t.begin(), t.end())) {
            break;
        }
    }
    cout << n - res;
} 
