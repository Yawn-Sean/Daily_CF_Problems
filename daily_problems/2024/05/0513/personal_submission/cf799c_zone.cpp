/*
url:      https://codeforces.com/problemset/problem/799/C
run time: 203 ms
*/

void solve() {
    int n, a, b;
    cin >> n >> a >> b;
    vector<vector<int>> C(a + 1), D(b + 1);
    for (int i = 0; i < n; i ++ ) {
        int v, cost;
        string op;
        cin >> v >> cost >> op;
        if (op == "C" && cost <= a) C[cost].push_back(v);
        else if (op == "D" && cost <= b) D[cost].push_back(v);
    }
    multiset<int> x, y;
    for (auto t: C) {
        for (auto tt: t) {
            x.insert(tt);
        }
    }
    for (auto t: D) {
        for (auto tt: t) {
            y.insert(tt);
        }
    }
    int ans = 0;
    if (!x.empty() && !y.empty()) ans += *x.rbegin() + *y.rbegin();
    for (int i = 0, j = a; i <= j; i ++, j --) {
        int mx = -1;
        for (auto t: C[i]) {
            if (i != j) {
                auto tt = x.find(t);
                x.erase(tt);
            }
            mx = max(mx, t);
        }
        if (!x.empty() && mx != -1) { 
            if (i != j) ans = max(ans, mx + *x.rbegin());
            else if (x.size() >= 2) ans = max(ans, mx + *prev(x.rbegin()));
        }
        for (auto t: C[j]) {
            auto tt = x.find(t);
            x.erase(tt);
        }
    }
    for (int i = 0, j = b; i <= j; i ++, j --) {
        int mx = -1;
        for (auto t: D[i]) {
            if (i != j) { 
                auto tt = y.find(t);
                y.erase(tt);
            }
            mx = max(mx, t);
        }
        if (!y.empty() && mx != -1){
            if (i != j) ans = max(ans, mx + *y.rbegin());
            else if (y.size() >= 2) ans = max(ans, mx + *prev(y.rbegin()));
        }

        for (auto t: D[j]) {
            auto tt = y.find(t);
            y.erase(tt);
        }
    }
    cout << ans << endl;
}
