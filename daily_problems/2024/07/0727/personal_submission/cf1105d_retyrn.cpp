using ai3 = array<int, 3>;
int n, m, p;
int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, -1, 0, 1};

void solve() {
    cin >> n >> m >> p;
    vector<int> s(p);
    cin >> s;
    
    vector<string> g(n);
    cin >> g;
    
    vector<queue<ai3>> q(p);
    for (int i = 0; i < n; i ++) {
        for (int j = 0; j < m; j ++) {
            if (isdigit(g[i][j])) {
                g[i][j] -= 1;
                q[(int)(g[i][j] - '0')].push({i, j, 0});
            }
        }
    }
    
    auto check = [&]() {
        for (int i = 0; i < p; i ++) {
            if (!em(q[i])) return true;
        }
        return false;
    };
    
    ll time = 1;
    while (check()) {
        for (int i = 0; i < p; i ++) {
            while (!em(q[i]) and q[i].front()[2] < time * s[i]) {
                auto [x, y, step] = q[i].front();
                q[i].pop();
                for (int j = 0; j < 4; j ++) {
                    int nx = x + dx[j], ny = y + dy[j];
                    if (nx >= 0 and ny >= 0 and nx < n and ny < m and g[nx][ny] == '.') {
                        g[nx][ny] = i + '0';
                        q[i].push({nx, ny, step + 1});
                    }
                }
            }
        }
        time ++;
    }
    
    vector<int> cnt(p);
    for (auto& s : g) {
        for (auto& c : s) {
            if (isdigit(c)) cnt[c - '0'] += 1;
        }
    }
    cout << cnt << endl;
}