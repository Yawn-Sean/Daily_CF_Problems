int n, u, e[N];

void solve1() {
    cin >> n >> u;
    for (int i = 1; i <= n; i++) {
        cin >> e[i];
    }
    double res = -1;
    int k = 3;
    for (int i = 1; i <= n - 2; i++) {
        int j = i + 1;
        while (k + 1 <= n && e[k + 1] - e[i] <= u) {
            k++;
        }
        if (i + 2 <= k && e[k] - e[i] <= u) {
            // cout << i << " " << j << " " << k << "\n";
            res = max(res, (1.0 * (e[k] - e[j])) / (e[k] - e[i]));
        }
    }
    printf("%.12lf\n", res);
}       