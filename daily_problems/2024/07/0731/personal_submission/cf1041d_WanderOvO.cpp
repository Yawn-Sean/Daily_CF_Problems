/*
考虑从每段只能直飞的线段的左端点开始飞
假设从第 i 个段的左端点开始飞
其实就是 segs[i] 到 segs[j] 都能飞过去，假设这段长度之和为 len
则 segs[j].y - segs[i].x - len < h
维护线段长度的前缀和，枚举 i，二分出最大的满足条件的 j
最后还要额外考虑一种情况，就是在最左边线段的左边某个地方开始飞，可以想象成所有线段向左平移，至多飞 2e9 远
*/

int T;
PII segs[N];
int n, h, s[N];

bool check(int l, int r) {
    return segs[r].y - segs[l].x - (s[r] - s[l - 1]) < h;
}

void solve1() {
    cin >> n >> h;
    for (int i = 1; i <= n; i++) {
        cin >> segs[i].x >> segs[i].y;
    }
    for (int i = 1; i <= n; i++) {
        s[i] = s[i - 1] + segs[i].y - segs[i].x;
    }
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int l = i, r = n, mid;
        while (l + 1 < r) {
            mid = (l + r) / 2;
            if (check(i, mid)) {
                l = mid;
            } else {
                r = mid;
            }
        }
        int maxlen = 2e9;
        if (check(i, r)) {
            int left_h = (segs[r].y - segs[i].x) - (s[r] - s[i - 1]);
            left_h = h - left_h;
            res = max(res, min(maxlen, left_h + segs[r].y - segs[i].x));
        } else {
            int left_h = (segs[l].y - segs[i].x) - (s[l] - s[i - 1]);
            left_h = h - left_h;
            res = max(res, min(maxlen, left_h + segs[l].y - segs[i].x));
        }
    }
    cout << res << '\n';
}             
