/*
每个 [i, i + l - 1] 的区间都肯定得有青蛙经过
经过的最多个数就是 [i, i + l - 1] 的石头数
考虑所有 [i, i + l - 1]，其中石头数最小的那个就是瓶颈，它限制了至多只能通过这么多青蛙
*/

int T;
int a[N], w, l, s[N];

void solve1() {
    cin >> w >> l;
    for (int i = 1; i < w; i++) {
        cin >> a[i];
        s[i] = s[i - 1] + a[i];
    }
    int res = 1e9 + 10;
    for (int i = 0; i + l < w; i++) {
        res = min(res, s[i + l] - s[i]);
    }
    cout << res << endl;
}       