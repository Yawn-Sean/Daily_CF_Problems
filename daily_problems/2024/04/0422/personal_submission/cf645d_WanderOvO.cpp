/*
前 ans 条边能否有一条链能够经过所有点
*/

int T;
int n, m;
vector<int> e[N];
PII edges[N];
int d[N], dp[N];

bool check(int ans) {
    for (int i = 1; i <= n; i++) {
        d[i] = 0;
        dp[i] = 0;
        e[i].clear();
    }
    for (int i = 1; i <= ans; i++) {
        int u = edges[i].x, v = edges[i].y;
        e[u].pb(v);
        d[v]++;
    }
    
    int cnt = 0, st = 0;
    for (int i = 1; i <= n; i++) {
        if (d[i] == 0) {
            st = i;
            cnt++;
        }
    }
    if (cnt > 1) {
        return false;
    }
    
    dp[st] = 1;
    queue<int> q;
    q.push(st);
    int mx = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : e[u]) {
            dp[v] = max(dp[v], dp[u] + 1);
            d[v]--;
            mx = max(mx, dp[v]);
            if (d[v] == 0) {
                q.push(v);
            }
        }
    }
    return mx == n;
}

void solve1() {
    cin >> n >> m;
    for (int i = 1; i <= m; i++) {
        cin >> edges[i].x >> edges[i].y;
    }
    
    int l = 0, r = m, mid;
    while (l + 1 < r) {
        mid = (l + r) / 2;
        if (check(mid)) {
            r = mid;
        } else {
            l = mid;
        }
    }
    if (check(l)) {
        cout << l << "\n";
    } else if (check(r)) {
        cout << r << "\n";
    } else {
        cout << "-1\n";
    }
}   