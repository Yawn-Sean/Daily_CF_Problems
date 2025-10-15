/*
枚举一个点 (i, j)，假设其值是 val
强制过 (i, j) 做平行于坐标轴的直线，则显然是选边界的染色比较好
然后，假如是横着的，就考虑竖着的坐标最小/最大的 val 的坐标是多少，竖着也是类似的
*/

int n, maxx[11], minx[11], maxy[11], miny[11];
string grid[M];

void meibao() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> grid[i];
        grid[i] = " " + grid[i];
    }
    for (int i = 0; i < 10; i++) {
        maxx[i] = -1;
        minx[i] = n + 1;
        maxy[i] = -1;
        miny[i] = n + 1;
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int val = grid[i][j] - '0';
            maxx[val] = max(maxx[val], i);
            minx[val] = min(minx[val], i);
            maxy[val] = max(maxy[val], j);
            miny[val] = min(miny[val], j);
        }
    }

    int ans[11] = {0};
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            int val = grid[i][j] - '0';
            int len1 = max(maxx[val] - i, i - minx[val]);
            int len2 = max(maxy[val] - j, j - miny[val]);
            ans[val] = max({
                ans[val],
                len1 * max(j - 1, n - j),
                len2 * max(i - 1, n - i)
            });
        }
    }
    for (int i = 0; i < 10; i++) {
        cout << ans[i] << " ";
    }
    cout << "\n";
}
