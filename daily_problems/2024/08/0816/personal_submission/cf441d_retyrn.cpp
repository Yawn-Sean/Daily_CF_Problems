int n, m;
vector<vector<int>> v;

void build(vector<int>& a) {
    v.clear();
    vector<bool> st(n + 1, false);
    for (int i = 1; i <= n; i ++) {
        if (st[i]) continue;
        int val1 = i, val2 = inf;
        st[i] = true;
        int j = i;
        while (a[j] != i) {
            if (a[j] < val1) val2 = val1, val1 = a[j];
            else if (a[j] < val2) val2 = a[j];
            j = a[j];
            st[j] = true;
        }
        if (val2 == inf) v.push_back({val1});
        else v.push_back({val2, val1});
    }
}
void solve() {
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i ++) {
        cin >> a[i];
    }
    cin >> m;
    build(a);
    
    vector<pii> res;
    if (n - sz(v) < m) {
        int times = m - (n - sz(v));
        while (times --) {
            vector<int> v1, v2;
            for (auto& vec : v) {
                if (em(v1)) v1 = vec;
                else if (em(v2)) v2 = vec;
                else if (v1.back() > vec.back()) {
                    v2 = v1, v1 = vec;
                }
                else if (v2.back() > vec.back()) {
                    v2 = vec;
                }
            }
            res.emplace_back(v1.back(), v2.back());
            swap(a[v1.back()], a[v2.back()]);
            build(a);
        }
    }
    
    if (n - sz(v) > m) {
        int times = n - sz(v) - m;
        while (times --) {
            vector<int> v1;
            for (auto& vec : v) {
                if (sz(vec) == 1) continue;
                if (em(v1) or v1.back() > vec.back()) v1 = vec;
            }
            int x = v1[sz(v1) - 1];
            int y = v1[sz(v1) - 2];
            res.emplace_back(x, y);
            swap(a[x], a[y]);
            build(a);
        }
    }
    
    cout << sz(res) << endl;
    for (auto& p : res) {
        cout << p << ' ';
    }
    cout << endl;
}