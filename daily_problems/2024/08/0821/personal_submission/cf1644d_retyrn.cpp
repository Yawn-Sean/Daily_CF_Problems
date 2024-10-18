int n, m, k, q;
vector<int> choose_row(maxn), choose_col(maxn);

void solve() {
    cin >> n >> m >> k >> q;
    int full_row = 0, full_col = 0;
    
    vector<pii> ops(q);
    cin >> ops;
    
    ll res = 1;
    for (int i = q - 1; i >= 0; i --) {
        int x = ops[i].fi, y = ops[i].se;
        x --, y --;
        // 计算这一次可以多几个
        int cur = 0;
        if (!choose_row[x]) {
            cur += m - full_col;
        }
        if (!choose_col[y]) {
            cur += n - full_row;
        }
        if (!choose_row[x]) full_row += 1, choose_row[x] = true;
        if (!choose_col[y]) full_col += 1, choose_col[y] = true;
        
        if (cur > 0) {
            res = res * k % mod;
        }
    }
    
    for (auto [x, y] : ops) {
        x --, y --;
        choose_row[x] = choose_col[y] = false;
    }
    cout << res << endl;
}