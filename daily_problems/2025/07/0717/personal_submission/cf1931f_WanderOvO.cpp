int T;
int n, k, d[N];
vector<int> a[N];
vector<int> e[N];
 
void solve1() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        d[i] = 0;
        e[i].clear();
    }
    for (int i = 1; i <= k; i++) {
        a[i].clear();
    }
    for (int i = 1; i <= k; i++) {
        int x;
        for (int j = 1; j <= n; j++) {
            cin >> x;
            a[i].push_back(x);
        }
    }
    if (k <= 1) {
        cout << "YES\n";
        return;
    }
    
    for (int i = 1; i <= k; i++) {
        for (int j = 1; j < n - 1; j++) {
            int u = a[i][j], v = a[i][j + 1];
            e[u].push_back(v);
            d[v]++;
        }
    }
    
    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) {
            q.push(i);
        }
    }
    
    int cnt = 0;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        cnt++;
        for (auto v : e[u]) {
            d[v]--;
            if (d[v] == 0) {
                q.push(v);
            }
        }
    }
    if (cnt < n) {
        cout << "NO\n";
    } else {
        cout << "YES\n";
    }
}
