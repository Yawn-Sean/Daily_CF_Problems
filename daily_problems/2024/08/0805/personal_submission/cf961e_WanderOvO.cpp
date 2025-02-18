/*
枚举 a[j]，快速在前 min(a[j], j - 1) 个数字里面找 >= j 的 a[i]
按照 min(a[j], j - 1) 单调递增的顺序去计算，就可以单调地加入候选的 a[i]
*/

int T;
int n, a[N];
PII b[N];
BIT bit;

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = min(a[i], n);
        b[i] = {min(a[i], i - 1), i};
    }
    sort(b + 1, b + n + 1);
    int idx = 0;
    bit.init(n);
    LL res = 0;
    for (int i = 1; i <= n; i++) {
        while (idx + 1 <= n && b[i].x >= idx + 1) {
            idx++;
            bit.add(a[idx], 1);
        }
        res += idx - bit.query(b[i].y - 1);
    }
    cout << res << "\n";
}                                                                                                              
