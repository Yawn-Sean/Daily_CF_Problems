/*
首先看第 i 行，其有 cnt 个不同的数，则至少要用 cnt 个数了
看 a[i][j] 在第 i 行中是第 k 大（去重）的数，则 a[i][j] 重新赋值之后至少是 k
考虑 a[i][j] 在第 j 列中（去重）排第几名，假设是第 rk 名
- rk <= k，则比较小的那些数一定不会增加新的颜色，只要考虑比较大的部分会不会多就好了
- rk > k，则 a[i][j] 要至少变成 rk 才行，然后再看更大的部分可能多大
*/ 

int a[M][M], n, m;
vector<int> rows[M];
vector<int> cols[M];

void meibao() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
            rows[i].push_back(a[i][j]);
        }
        sort(rows[i].begin(), rows[i].end());
        rows[i].erase(unique(rows[i].begin(), rows[i].end()), rows[i].end());
    }
    for (int j = 1; j <= m; j++) {
        for (int i = 1; i <= n; i++) {
            cols[j].push_back(a[i][j]);
        }
        sort(cols[j].begin(), cols[j].end());
        cols[j].erase(unique(cols[j].begin(), cols[j].end()), cols[j].end());
    }

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int row_rk = lower_bound(rows[i].begin(), rows[i].end(), a[i][j]) - rows[i].begin();
            int col_rk = lower_bound(cols[j].begin(), cols[j].end(), a[i][j]) - cols[j].begin();
            row_rk++;
            col_rk++;
            int row_cnt = rows[i].size(), col_cnt = cols[j].size();
            int min_aij = max(row_rk, col_rk);
            int mx = min_aij + max(row_cnt - row_rk, col_cnt - col_rk);
            cout << mx << " ";
        }
        cout << "\n";
    }
}
