/*
考虑所有度为 1 的点，最远点应该是两个度为 1 的点的距离
*/

int T;
int d[N], n, s;

void solve1() {
    cin >> n >> s;
    for (int i = 1; i < n; i++) {
        int u, v;
        cin >> u >> v;
        d[u]++;
        d[v]++;
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 1) {
            cnt++;
        }
    }
    cout << setprecision(12) << (2.0 * s) / cnt << "\n";
}              