/*
如果 m = n * (n - 1)，则所有的都枚举到了
第一个数组中不可能有相等的，所以第二组中的 (a[i], b[i]) 不能有相等的
不妨默认第一个就是 1234...n，则只要 a[i] < b[i]，就是小于，否则就是大于
m = 1e5
n > 320 时，一定有没被列举出的关系，这俩数在第一个数组中应该是相邻的数，才能保证第二个数组中比较结果不变
*/

int T;
int n, m, a[N], b[N];

void solve1() {
    cin >> n >> m;
    set<PII> s;
    for (int i = 1; i <= m; i++) {
        int u, v;
        cin >> u >> v;
        if (u > v) {
            swap(u, v);
        }
        s.insert({u, v});
    }
    bool found = false;
    int pos1, pos2;
    for (int i = 1; i <= n && !found; i++) {
        for (int j = i + 1; j <= n && !found; j++) {
            if (!s.count({i, j})) {
                pos1 = i;
                pos2 = j;
                found = true;
            }
        }
    }
    if (!found) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";
    for (int i = 1; i <= n; i++) {
        a[i] = 0;
        b[i] = 0;
    }
    a[pos1] = 1;
    a[pos2] = 2;
    b[pos1] = 1;
    b[pos2] = 1;
    int idx = 3;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 0) {
            a[i] = idx++;
        }
    }
    idx = 3;
    for (int i = 1; i <= n; i++) {
        if (b[i] == 0) {
            b[i] = idx++;
        }
    }
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << "\n";
    for (int i = 1; i <= n; i++) {
        cout << b[i] << " ";
    }
    cout << "\n";
}                 
