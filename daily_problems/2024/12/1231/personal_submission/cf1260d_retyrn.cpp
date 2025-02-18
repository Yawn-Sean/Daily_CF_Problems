int m, n, k, t;
using ai3 = array<int, 3>;

void solve() {
    cin >> m >> n >> k >> t;
    vector<int> a(m);
    cin >> a;
    sort(all(a), greater<int>());
    
    vector<ai3> b(k);
    for (int i = 0; i < k; i ++) {
        for (int j = 0; j < 3; j ++) {
            cin >> b[i][j];
        }
    }
    
    vector<int> v(n + 2);
    auto check = [&](int len) -> bool {
        int val = (len == 0 ? inf : a[len - 1]);
        // 耐毒性最低的是val, 大于val的全部要清除
        fill(all(v), 0);
        for (auto [l, r, d] : b) {
            if (d <= val) continue;
            v[l] ++;
            v[r + 1] --;
        }
        int need = 0;
        for (int i = 1; i <= n + 1; i ++) {
            v[i] += v[i-1];
            need += (v[i] > 0 ? 3 : 1);
        }
        return need <= t;
    };
    
    int l = 0, r = m;
    while (l < r) {
        auto mid = (l + r + 1) >> 1;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
}