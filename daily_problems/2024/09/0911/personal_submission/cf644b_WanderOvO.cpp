int T;
int n, b;
LL d[N], t[N];

void solve1() {
    cin >> n >> b;
    for (int i = 1; i <= n; i++) {
        cin >> t[i] >> d[i];
    }
    
    queue<LL> q;
    for (int i = 1; i <= n; i++) {
        while (!q.empty() && q.front() <= t[i]) {
            q.pop();
        }
        if (q.size() > b) {
            cout << "-1 ";
            continue;
        }
        LL cur = t[i];
        if (!q.empty()) {
            cur = q.back();
        }
        q.push(cur + d[i]);
        cout << cur + d[i] << " ";
    }
}      
