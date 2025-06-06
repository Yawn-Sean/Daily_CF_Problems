/*
数位 DP 求包含 i 个 4 和 j 个 7 的数的个数
背包 DP 求不超过 cnt 个 4 和 7 的方案数
*/

LL m, c[M][M], cnt[M];
LL dp1[M][M][M], dp2[M][M][M];
string s;
int n;
int mod = 1e9 + 7;

LL qpow(LL a, LL b, LL MOD) {
    LL res = 1, base = a;
    while (b) {
        if (b & 1) {
            res = res * base % MOD;
        }
        base = base * base % MOD;
        b >>= 1;
    }
    return res % MOD;
}

LL inv(LL x) {
    return qpow(x, mod - 2, mod);
}

LL C(LL a, LL b) {
    if (a < b) return 0;
    LL res = 1;
    for (LL i = a; i > a - b; i--) {
        res *= i;
        res %= mod;
    }
    for (int i = 2; i <= b; i++) {
        res *= inv(i);
        res %= mod;
    }
    return res;
}

LL dfs(LL t, LL cnt4, LL cnt7, bool is_num, bool is_limit) {
    if (t == n) {
        if (cnt4 == 0 && cnt7 == 0 && is_num) {
            return 1;
        }
        return 0;
    }

    if (!is_limit && is_num && dp1[t][cnt4][cnt7] >= 0) {
        return dp1[t][cnt4][cnt7];
    }

    LL res = 0;
    if (!is_num) {
        res = dfs(t + 1, cnt4, cnt7, false, false);
    }

    int up = is_limit ? (s[t] - '0') : 9;
    int down = is_num ? 0 : 1;

    for (int d = down; d <= up; d++) {
        if (d == 4) {
            res += dfs(t + 1, cnt4 - 1, cnt7, true, is_limit && d == up);
        } else if (d == 7) {
            res += dfs(t + 1, cnt4, cnt7 - 1, true, is_limit && d == up);
        } else {
            res += dfs(t + 1, cnt4, cnt7, true, is_limit && d == up);
        }
        res %= mod;
    }

    if (!is_limit && is_num) {
        dp1[t][cnt4][cnt7] = res;
    }
    return res;
}

void meibao() {
    cin >> m;
    s = to_string(m);
    n = s.size();
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            memset(dp1, -1, sizeof dp1);
            c[i][j] = dfs(0, i, j, false, true);
        }
    }

    memset(cnt, 0, sizeof cnt);
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < M; j++) {
            if (i + j < M) {
                cnt[i + j] += c[i][j];
            }
        }
    }

    LL res = 0;
    for (int first_cnt = 0; first_cnt < M; first_cnt++) {
        memset(dp2, 0, sizeof dp2);
        for (int j = 0; j < 7; j++) {
            dp2[0][j][0] = C(cnt[0], j);
        }

        for (int i = 1; i < M; i++) {
            for (int j = 0; j < 7; j++) {
                for (int k = 0; k < first_cnt; k++) {
                    for (int l = 0; l < M; l++) {
                        if (j - l >= 0 && k - i * l >= 0) {
                            dp2[i][j][k] += dp2[i - 1][j - l][k - i * l] * C(cnt[i], l);
                            dp2[i][j][k] %= mod;
                        }
                    }
                }
            }
        }

        for (int k = 0; k < first_cnt; k++) {
            res += (dp2[M - 1][6][k] * cnt[first_cnt] % mod) * 720;
            res %= mod;
        }
    }
    cout << res << "\n";
}   
