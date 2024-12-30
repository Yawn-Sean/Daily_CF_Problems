/*
能否直接算每个 a[i] 至多坚持多久？
考虑每个 a[i]
考虑每个 j >= i，答案是 min(min(a[j] + j) - i, i, n - i + 1)
考虑每个 j <= i，答案是 min(min(a[j] - j) + i, i, n - i + 1)
所有的 max 就是答案
*/

int T;
int n, a[N];
int pre[N], suf[N];

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
    }
    pre[1] = a[1] - 1;
    for (int i = 2; i <= n; i++) {
        pre[i] = min(pre[i - 1], a[i] - i);
    }
    suf[n] = a[n] + n;
    for (int i = n - 1; i > 0; i--) {
        suf[i] = min(suf[i + 1], a[i] + i);
    }
    int res = 1;
    for (int i = 2; i < n; i++) {
        int res1 = min({suf[i] - i, i, n - i + 1});
        int res2 = min({pre[i] + i, i, n - i + 1});
        res = max(res, min(res1, res2));
    }
    cout << res << "\n";
}         