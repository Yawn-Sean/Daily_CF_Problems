/*
一个朴素的思路是一红一蓝，看看能不能符合题意
每个区间包含的一定是相邻的点，要么包含奇数个，要么包含偶数个
只要是相邻的，就一定能保证差距 <= 1

*/

int n, m;
PII ps[N], segs[N];

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> ps[i].x;
        ps[i].y = i;
    }
    for (int i = 1; i <= m; i++) {
        cin >> segs[i].x >> segs[i].y;
    }
    sort(ps + 1, ps + n + 1);
    vector<int> res(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        res[ps[i].y] = (i % 2);
    }
    for (int i = 1; i <= n; i++) {
        cout << res[i] << " ";
    }
}
