int T;
char s[N];
int same[N];
 
void solve1() {
    cin >> (s + 1);
    int n = strlen(s + 1);
    int res = 0;
    for (int len = 2; len <= n; len += 2) {
        int t = len / 2;
        for (int i = 1; i <= n; i++) {
            same[i] = 0;
        }
        for (int l = 1; l + t <= n; l++) {
            if (s[l] == '?' || s[l + t] == '?' || s[l] == s[l + t]) {
                same[l] = 1;
            } else {
                same[l] = 0;
            }
        }
        for (int l = 1; l <= n; l++) {
            same[l] += same[l - 1];
        }
        // 如果 [l, l + len - 1] 符合题意，那么 same[l + t - 1] - same[l - 1] == t
        for (int l = 1; l + len - 1 <= n; l++) {
            if (same[l + t - 1] - same[l - 1] == t) {
                res = max(res, len);
            }
        }
    }
    cout << res << "\n";
}
