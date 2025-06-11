/*
4 行
3 行 1 列
2 行 2 列
1 行 3 列
4 列
4 行或者 4 列的直接贪心选最大的 4 个即可
3 行 1 列的，枚举列，然后把行的值减掉选择的列的，贪心选前 3 大的，1 行 3 列同理
2 行 2 列的？枚举比较少的那个
*/

int T;
LL n, m;
vector<vector<LL>> a;
vector<LL> row_sum, col_sum;

void solve1() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        vector<LL> r;
        LL sum = 0;
        for (int j = 0; j < m; j++) {
            LL val;
            cin >> val;
            sum += val;
            r.pb(val);
        }
        a.pb(r);
        row_sum.pb(sum);
    }

    for (int j = 0; j < m; j++) {
        LL sum = 0;
        for (int i = 0; i < n; i++) {
            sum += a[i][j];
        }
        col_sum.pb(sum);
    }

    if (n <= 4 || m <= 4) {
        LL res = 0;
        for (int i = 0; i < n; i++) {
            res += row_sum[i];
        }
        cout << res << "\n";
        return;
    }

    LL res = 0;
    vector<LL> vals;
    for (int i = 0; i < n; i++) {
        vals.pb(row_sum[i]);
    }
    sort(vals.begin(), vals.end());
    reverse(vals.begin(), vals.end());
    LL sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += vals[i];
    }
    res = max(res, sum);

    vals.clear();
    for (int i = 0; i < m; i++) {
        vals.pb(col_sum[i]);
    }
    sort(vals.begin(), vals.end());
    reverse(vals.begin(), vals.end());
    sum = 0;
    for (int i = 0; i < 4; i++) {
        sum += vals[i];
    }
    res = max(res, sum);

    // 1 行 3 列
    for (int i = 0; i < n; i++) {
        vals.clear();
        sum = row_sum[i];
        for (int j = 0; j < m; j++) {
            vals.pb(col_sum[j] - a[i][j]);
        }
        sort(vals.begin(), vals.end());
        reverse(vals.begin(), vals.end());
        for (int j = 0; j < 3; j++) {
            sum += vals[j];
        }
        res = max(res, sum);
    }

    // 1 列 3 行
    for (int j = 0; j < m; j++) {
        priority_queue<LL, vector<LL>, greater<LL>> q;
        sum = col_sum[j];
        for (int i = 0; i < n; i++) {
            LL s = row_sum[i] - a[i][j];
            if (q.size() < 3) {
                q.push(s);
            } else {
                if (s > q.top()) {
                    q.pop();
                    q.push(s);
                }
            }
        }
        while (q.size() > 0) {
            sum += q.top();
            q.pop();
        }
        res = max(res, sum);
    }

    if (n <= m) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                sum = row_sum[i] + row_sum[j];
                priority_queue<LL, vector<LL>, greater<LL>> q;
                for (int k = 0; k < m; k++) {
                    LL s = col_sum[k] - a[i][k] - a[j][k];
                    if (q.size() < 2) {
                        q.push(s);
                    } else {
                        if (s > q.top()) {
                            q.pop();
                            q.push(s);
                        }
                    }
                }
                while (!q.empty()) {
                    sum += q.top();
                    q.pop();
                }
                res = max(res, sum);
            }
        }
    } else {
        for (int i = 0; i < m; i++) {
            for (int j = i + 1; j < m; j++) {
                sum = col_sum[i] + col_sum[j];
                priority_queue<LL, vector<LL>, greater<LL>> q;
                for (int k = 0; k < n; k++) {
                    LL s = row_sum[k] - a[k][i] - a[k][j];
                    if (q.size() < 2) {
                        q.push(s);
                    } else {
                        if (s > q.top()) {
                            q.pop();
                            q.push(s);
                        }
                    }
                }
                while (!q.empty()) {
                    sum += q.top();
                    q.pop();
                }
                res = max(res, sum);
            }
        }
    }
    cout << res << "\n";
}      