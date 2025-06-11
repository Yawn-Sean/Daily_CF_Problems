// https://codeforces.com/contest/863/submission/267274674
bool cmp(int a, int b) {
    if (a == 1 && b == 3) return true;
    if (a == 3 && b == 2) return true;
    if (a == 2 && b == 1) return true;
    return false;
}
void sol()
{
    LL k;
    int a, b;
    cin >> k >> a >> b;
    vector<vector<int>> A(3, vector<int>(3));
    vector<vector<int>> B(3, vector<int>(3));
    int x, y, z;
    for (int i = 0; i < 3; i++) {
        cin >> x >> y >> z;
        A[i] = {x, y, z}; 
    }
    for (int i = 0; i < 3; i++) {
        cin >> x >> y >> z;
        B[i] = {x, y, z}; 
    }
    vector<vector<int>> vis(4, vector<int>(4, 0));
    vector<PII> period;
    int c;
    while (vis[a][b] == 0) {
        period.push_back({a, b});
        vis[a][b] = 1;
        c = a;
        a = A[a - 1][b - 1];
        b = B[c - 1][b - 1];
    }
    // 计算周期，起始位置和长度
    int len = 0, start = 0;
    for (int i = 0; i < period.size(); i++) {
        auto [x, y] = period[i];
        if (x == a && y == b) {
            len = period.size() - i;
            start = i;
        }
    }
    // 计算周期内的增量
    LL delta_a = 0, delta_b = 0;
    for (int i = start; i < period.size(); i++) {
        auto [x, y] = period[i];
        if (cmp(x, y)) delta_a++;
        if (cmp(y, x)) delta_b++;
    }
    // 分为三部分：头部，周期，尾部
    LL cnt = 0;
    LL res_a = 0, res_b = 0;
    for (int i = 0; i < start && cnt < k; i++) {
        auto [x, y] = period[i];
        if (cmp(x, y)) res_a++;
        if (cmp(y, x)) res_b++;
        cnt++;
    }
    LL old = k;
    k -= cnt;
    LL q = k / len, r = k % len;
    cnt += q * len;
    for (int i = start; i < start + r && cnt < old; i++) {
        auto [x, y] = period[i];
        if (cmp(x, y)) res_a++;
        if (cmp(y, x)) res_b++;
        cnt++;
    }
    res_a += q * delta_a, res_b += q * delta_b;
    cout << res_a << " " << res_b << '\n';
}
