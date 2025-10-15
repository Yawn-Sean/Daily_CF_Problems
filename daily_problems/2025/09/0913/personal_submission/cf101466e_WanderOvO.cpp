/*
给两个串 s 和 t，求 t 的一个最长前缀，使得 t 在 s 中出现了至少 n 次
显然越短的前缀越容易出现至少 n 次，有单调性，可以二分
可以二分 + 哈希去判断是否符合题意
*/

struct Hash {
    LL h[N], p[N], P, mod;

    void init(char s[], int n, int PP, int MOD) {
        h[0] = 0;
        p[0] = 1;
        P = PP;
        mod = MOD;
        for (int i = 1; i <= n; i++) {
            h[i] = P * h[i - 1] + s[i];
            h[i] %= mod;
            p[i] = p[i - 1] * P % mod;
        }
    }

    int query(int l, int r) {
        return ((h[r] - h[l - 1] * p[r - l + 1] % mod) + mod) % mod;
    }
};

Hash s1, s2, t1, t2;
char s[N], t[N];

void meibao() {
    fgets(s + 1, N, stdin);
    fgets(t + 1, N, stdin);
    
    int cnt;
    scanf("%d", &cnt);

    // 去掉行末换行
    int len_s = strlen(s + 1) - 1, len_t = strlen(t + 1) - 1;
    s1.init(s, len_s, P, MOD1);
    s2.init(s, len_s, P, MOD2);
    t1.init(t, len_t, P, MOD1);
    t2.init(t, len_t, P, MOD2);

    int l = 1, r = len_t, mid;

    auto check = [&] (int ans) -> bool {
        int val1 = t1.query(1, ans), val2 = t2.query(1, ans);
        int match_cnt = 0;
        for (int l = 1; l + ans - 1 <= len_s; l++) {
            int v1 = s1.query(l, l + ans - 1), v2 = s2.query(l, l + ans - 1);
            if (v1 == val1 && v2 == val2) {
                match_cnt++;
            }
        }
        return match_cnt >= cnt;
    };

    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            l = mid;
        } else {
            r = mid;
        }
    }

    int res = 0;
    if (check(r)) {
        res = r;
    } else if (check(l)) {
        res = l;
    }
    if (res == 0) {
        cout << "IMPOSSIBLE\n";
    } else {
        for (int i = 1; i <= res; i++) {
            cout << t[i];
        }
        cout << "\n";
    }
}   
