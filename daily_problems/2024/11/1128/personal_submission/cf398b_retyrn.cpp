int n, m;

void solve() {
    cin >> n >> m;
    vector<vector<double>> f(n + 1, vector<double>(n + 1)); // f[i][j] 有i行j列需要涂色的步数期望
    vector<int> row(n + 1), col(n + 1);
    while (m --) {
        int x, y;
        cin >> x >> y;
        row[x] = 1;
        col[y] = 1;
    }
    
    int x = n - accumulate(all(row), 0);
    int y = n - accumulate(all(col), 0);
    
    f[0][0] = 0;

    for (int i = 0; i <= x; i ++) {
        for (int j = 0; j <= y; j ++) {
            if (i == 0 and j == 0) continue;
            double up = n * n;
            if (i) up += f[i-1][j] * i * (n-j);
            if (j) up += f[i][j-1] * (n-i) * j;
            if (i and j) up += f[i-1][j-1] * i * j;
            f[i][j] = up / (n * n - (n-i) * (n-j));
        }
    }
    cout << f[x][y] << endl;
}