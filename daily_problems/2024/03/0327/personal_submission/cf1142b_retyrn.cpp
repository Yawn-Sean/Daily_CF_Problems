int n, m, q;
 
//-----------------------function-----------------------
 
void solve() {
    cin >> n >> m >> q;
    vector<int> p(n);
    for (int i = 0; i < n; i ++) {
        int x;
        cin >> x;
        x --;
        p[x] = i;
    }
    vector<int> a(m);
    for (int i = 0; i < m; i ++) {
        cin >> a[i];
        a[i] --;
        a[i] = p[a[i]];
    }
    // 需要寻找 i,i+1, ...n, 1, 2, .. i-1
    // 只要找到第一个位置, 结束位置是确定的
    vector<int> pos(n, -1);
    vector<int> next(m, -1);
    for (int i = m - 1; i >= 0; i --) {
        next[i] = pos[(a[i] + 1) % n];
        pos[a[i]] = i;
    }
    
    // 预处理每个位置走2^0 2^1 2^2 2^3...步的
    vector<vector<int>> step(m, vector<int>(18, -1));
    for (int i = 0; i < m; i ++) {
        step[i][0] = next[i];
    }
    for (int j = 1; j < 18; j ++) {
        for (int i = 0; i < m; i ++) {
            if (step[i][j - 1] < 0) step[i][j] = -1;
            else {
                step[i][j] = step[step[i][j-1]][j-1];
            }
        }
    }
    vector<int> res(m, inf);
    for (int i = 0; i < m; i ++) {
        int p = i;
        for (int j = 0; j < 18; j ++) {
            if ((n - 1) >> j & 1) p = step[p][j];
            if (p < 0) break;
        }
        if (p >= 0) {
            res[i] = p;
        }
    }
    
    // 如果范围是[l, r] 那么l+1
    int mn = inf;
    for (int i = m - 1; i >= 0; i --) {
        if (mn > res[i]) mn = res[i];
        else res[i] = mn;
    }
    
    string s;
    while (q -- ) {
        int l, r;
        cin >> l >> r;
        l --, r --;
        if (res[l] <= r) {
            s += '1';
        }
        else {
            s += '0';
        }
    }
    cout << s << endl;
}
int main() {
    FAST;
    // Tsolve();
    solve();
 
    return 0;
}