// https://codeforces.com/contest/1878/submission/257396918
int n, t, m, k, q;
char s[MAXN];
int l[MAXN], r[MAXN];
int x[MAXN];
int cnt[MAXN];
void sol()
{
    scanf("%d %d", &n, &k);
    scanf("%s", s + 1);
    for (int i = 1; i <= k; i++) scanf("%d", &l[i]);
    for (int i = 1; i <= k; i++) scanf("%d", &r[i]);
    scanf("%d", &q);
    for (int i = 1; i <= q; i++) scanf("%d", &x[i]);

    memset(cnt, 0, sizeof(cnt));
    for (int i = 1; i <= q; i++) {
        int head = 1, tail = k, cur = x[i];
        while (head < tail) {
            int mid = (head + tail + 1 ) / 2;
            if (l[mid] <= cur) head = mid;
            else tail = mid - 1;
        }
        int minv = min(cur, r[tail] + l[tail] - cur);
        int maxv = max(cur, r[tail] + l[tail] - cur);
        cnt[minv]++;
        cnt[maxv + 1]--;
    }
    for (int i = 1; i <= n; i++) {
        cnt[i] = cnt[i - 1] + cnt[i];
    }
    for (int i = 1; i <= n; i++) {
        if (cnt[i] & 1) cnt[i] = 1;
        else cnt[i] = 0;
    }
    for (int idx = 1; idx <= k; idx++) {
        for (int i = l[idx], j = r[idx]; i < j; i++, j--)
                if (cnt[i] == 1)
                    swap(s[i], s[j]);
    }
    printf("%s\n", s + 1);
}
