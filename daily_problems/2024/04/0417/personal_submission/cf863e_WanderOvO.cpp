/*
使用动态开点线段树，每个电视做区间加
最后看每个电视所在区间最小值是否 > 1 即可
*/

int T;
int l[N], r[N];
int n, m, idx, root;
Node tr[M];

void solve1() {
    cin >> n;
    build(0, INF, root);
    for (int i = 1; i <= n; i++) {
        cin >> l[i] >> r[i];
        add(0, INF, l[i], r[i], 1, root);
    }
    for (int i = 1; i <= n; i++) {
        if (query(0, INF, l[i], r[i], 1) > 1) {
            cout << i << "\n";
            return;
        }
    }
    cout << "-1\n";
}        