/*
类似糖果传递，但是可以看成环形只能往一个方向传递糖果
余数为 i 的数的个数记为 a[i]
记 i 给 (i + 1) % m 传递了 x[i] 个数，由于只能单向传递，所以 x[i] >= 0
目标最小化 x[1] + ... + x[m]
a[i] - x[i] + x[i - 1] = avg, avg = n / m
a[0] - x[0] + x[m - 1] = avg
x[0] = x[m - 1] - (avg - a[0])
x[i] = x[m - 1] - ((i + 1) * avg - a[0] - ... - a[i])
x[m - 2] = x[m - 1] - ((m - 1) * avg - a[0] - ... - a[m - 2])
x[m - 1] = x[m - 1]
强制了 x[m - 1] 在所有点的右边，且 x[m - 1] >= 0
显然 x[m - 1] 和最右边的点重合时，整个表达式最小
*/

int T;
LL n, m, b[N], a[N], x[N];

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        a[b[i] % m]++;
    }
    LL avg = n / m;
    LL mx = 0, s = 0;
    for (int i = 0; i < m; i++) {
        s += avg - a[i];
        mx = max(mx, s);
    }
    x[m - 1] = mx;
    s = 0;
    for (int i = 0; i < m - 1; i++) {
        s += avg - a[i];
        x[i] = x[m - 1] - s;
    }
    LL res = 0;
    for (int i = 0; i < m; i++) {
        res += x[i];
    }
    cout << res << "\n";
    vector<vector<int>> cur(m);
    for (int i = 1; i <= n; i++) {
        cur[b[i] % m].pb(i);
    }
    vector<int> stk;
    for (int i = 0; i < 2 * m; i++) {
        int r = i % m;
        while (stk.size() && cur[r].size() < avg) {
            int j = stk.back();
            stk.pop_back();
            int op_cnt = (r - b[j] % m + m) % m;
            b[j] += op_cnt;
            cur[r].pb(j);
        }
        while (cur[r].size() > avg) {
            int j = cur[r].back();
            cur[r].pop_back();
            stk.pb(j);
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
}           