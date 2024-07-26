ll n;
int sa, sb;

int get(int x, int y) {
    if (x == 3 and y == 2) return 1;
    if (x == 2 and y == 1) return 1;
    if (x == 1 and y == 3) return 1;
    return 0;
}

void solve() {
    cin >> n >> sa >> sb;
    vector<vector<int>> a(4, vector<int>(4));
    auto b = a;
    for (int i = 1; i <= 3; i ++) {
        for (int j = 1; j <= 3; j ++) {
            cin >> a[i][j];
        }
    }
    for (int i = 1; i <= 3; i ++) {
        for (int j = 1; j <= 3; j ++) {
            cin >> b[i][j];
        }
    }
    
    vector<vector<int>> seen(4, vector<int>(4, 0));
    vector<vector<int>> A(4, vector<int>(4, 0));
    vector<vector<int>> B(4, vector<int>(4, 0));
    
    // 有循环
    int cur1 = 0, cur2 = 0;
    int cnt = 1;
    while (!seen[sa][sb] and n > 0) {
        A[sa][sb] = cur1, B[sa][sb] = cur2;
        cur1 += get(sa, sb);
        cur2 += get(sb, sa);
        auto t1 = a[sa][sb], t2 = b[sa][sb];
        seen[sa][sb] = cnt ++;
        sa = t1;
        sb = t2;
        n --;
    }
    if (n == 0) {
        cout << cur1 << ' ' << cur2 << endl;
        return;
    }
    int d = (cnt - seen[sa][sb]);
    
    ll res1 = n / d * (cur1 - A[sa][sb]) + cur1;
    ll res2 = n / d * (cur2 - B[sa][sb]) + cur2;
    n %= d;
    while (n > 0) {
        res1 += get(sa, sb);
        res2 += get(sb, sa);
        auto t1 = a[sa][sb], t2 = b[sa][sb];
        sa = t1;
        sb = t2;
        n -= 1;
    }
    cout << res1 << ' ' << res2 << endl;
}