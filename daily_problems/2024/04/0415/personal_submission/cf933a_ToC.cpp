// https://codeforces.com/contest/933/submission/256790217
int n, t, m;
int s[MAXN];
void sol()
{
    scanf("%d", &n);
    int cnt1 = 0;
    for (int i = 1; i <= n; i++) {
        scanf("%d", &s[i]);
        if (s[i] == 1)
            cnt1++;
    }
    if (cnt1 == 0 || cnt1 == n) {
        printf("%d\n", n);
    } else {
        vector<int> pre(n + 1), suf(n + 1);
        for (int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] + (s[i] == 1);

        suf[n] = (s[n] == 2);
        for (int i = n - 1; i >= 1; i--) 
            suf[i] = suf[i + 1] + (s[i] == 2);

        int res = 0;
        for (int i = 1; i < n; i++) {
            if (pre[i] != 0 && suf[i + 1] != 0)
                res = max(res, pre[i] + suf[i + 1]);
        }

        int f1 = 0, f12 = 0, f121 = 0, f1212 = 0;
        for (int i = 1; i <= n; i++) {
            if (s[i] == 1) {
                f1++;
                // if (f12 != 0) f121 = max(f12 + 1, f121 + 1);
                f121 = max(f12 + 1, f121 + 1);
            } else {
                // if (f1 != 0) f12 = max(f1 + 1, f12 + 1);
                f12 = max(f1 + 1, f12 + 1);
                // if (f121 != 0) f1212 = max(f121 + 1, f1212 + 1);
                f1212 = max(f121 + 1, f1212 + 1);
            }
        }
        res = max(res, max(f1, max(f12, max(f121, f1212))));
        printf("%d\n", res);
        
    }
}
