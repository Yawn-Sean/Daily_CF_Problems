/*
如果第一组选的 a[i] < b[i]，则后面都得选 a[j] < b[j] 的
a[i] > b[i] 同理
先分组，所有 a[i] < b[i] 的分一组，a[i] > b[i] 的分一组，记录一下原始编号
怎么排？
对于 a[i] < b[i] 的，按照 a[i] 升序排序，然后只要按照 n, n - 1, ... 2 1 的顺序排即可
对于 a[i] > b[i] 的，按照 a[i] 升序排序，然后只要按照 1 2 3 4 ... 的顺序排即可
*/

int T;
int n, cnt1, cnt2;
PIII up[N], down[N];

bool cmp(const PIII &a, const PIII &b) {
    if (a.x.x == b.x.x) {
        if (a.x.y == b.x.y) {
            return a.y < b.y;
        }
        return a.x.y < b.x.y;
    }
    return a.x.x < b.x.x;
}

void solve1() {
    cin >> n;
    int a, b;
    for (int i = 1; i <= n; i++) {
        cin >> a >> b;
        if (a < b) {
            up[++cnt1] = mp(mp(a, b), i);
        } else {
            down[++cnt2] = mp(mp(a, b), i);
        }
    }
    sort(up + 1, up + cnt1 + 1, cmp);
    sort(down + 1, down + cnt2 + 1, cmp);
    vector<int> res;
    if (cnt1 > cnt2) {
        cout << cnt1 << "\n";
        for (int i = cnt1; i > 0; i--) {
            res.pb(up[i].y);
        }
    } else {
        cout << cnt2 << "\n";
        for (int i = 1; i <= cnt2; i++) {
            res.pb(down[i].y);
        }
    }
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << " ";
    }
}                 