/*
先统计每种鱼捉了多少只
本质上就是，按照 type 排序，找一个后缀，使得 A 的后缀 cnt 的和 > B 的后缀 cnt 的和，这样重量拉到 INF 就行了
*/

vector<PLL> f1, f2;
int n, m, k;

void meibao() {
    cin >> n >> m >> k;
    map<LL, LL> cnt1, cnt2;
    for (int i = 1; i <= n; i++) {
        int type;
        cin >> type;
        cnt1[type]++;
    }
    for (int i = 1; i <= m; i++) {
        int type;
        cin >> type;
        cnt2[type]++;
    }

    for (auto &it : cnt1) {
        f1.push_back({it.x, it.y});
    }
    for (auto &it : cnt2) {
        f2.push_back({it.x, it.y});
    }
    sort(f1.begin(), f1.end());
    sort(f2.begin(), f2.end());
    reverse(f1.begin(), f1.end());
    reverse(f2.begin(), f2.end());
    LL sum1 = 0, sum2 = 0;
    int p1 = 0, p2 = 0;
    for ( ; p1 < f1.size() && p2 < f2.size(); ) {
        if (f1[p1].x > f2[p2].x) {
            sum1 += f1[p1].y;
            p1++;
        } else if (f1[p1].x < f2[p2].x) {
            sum2 += f2[p2].y;
            p2++;
        } else {
            sum1 += f1[p1].y;
            sum2 += f2[p2].y;
            p1++;
            p2++;
        }
        if (sum1 > sum2) {
            cout << "YES\n";
            return;
        }
    }
    while (p1 != f1.size()) {
        sum1 += f1[p1].y;
        p1++;
    }
    cout << (sum1 > sum2 ? "YES" : "NO") << "\n";
}
