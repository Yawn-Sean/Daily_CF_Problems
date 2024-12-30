/*
所有和 a[1] 相等的 a[i]，都得填 0
由于单调不减，所以对于 a[1] = a[i] 的最大的 i，要让 b[1] 到 b[i] 都是 0
假如对于某个 val，a[i] = a[j] = val，则 b[i] 到 b[j] 这个区间都得相等
假如有相交的区间，则也都得相等
把相交区间缩成一个点，则只需要考虑这些点单调不减即可
除了第一个点一定是 0，后面的都可以选择和前面一样，或者 + 1
所以答案一定是 2 的幂
*/

int T;
LL n, a[N], b[N];
int l[N], r[N];
vector<PII> seg;

void solve1() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        b[i] = a[i];
    }
    sort(b + 1, b + n + 1);
    for (int i = 1; i <= n; i++) {
        int pos = lower_bound(b + 1, b + n + 1, a[i]) - b;
        a[i] = pos;
    }
    
    for (int i = 1; i <= n; i++) {
        if (l[a[i]] == 0) {
            l[a[i]] = i;
        } 
        r[a[i]] = i;
    }
    
    for (int i = 1; i <= n; i++) {
        if (l[i] != 0) {
            seg.pb({l[i], r[i]});
        }
    }
    sort(seg.begin(), seg.end());
    int right = seg[0].y;
    int cnt = 1;
    for (int i = 1; i < seg.size(); i++) {
        if (seg[i].x > right) {
            cnt++;
        }
        right = max(right, seg[i].y);
    }
    cout << qpow(2, cnt - 1, MOD2) << "\n";
}            