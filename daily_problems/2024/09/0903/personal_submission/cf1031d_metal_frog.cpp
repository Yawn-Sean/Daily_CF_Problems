const int N = 2006;
string G[N];
int cnta[N][N];
bool vis[N][N];

void solve() {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        cin >> G[i];
        for (int j = 0; j < n; j++) {
            cnta[i][j] = -1;
        }
    }    
    cnta[0][0] = (G[0][0] == 'a');
    for (int c = 1; c < n; c++) {
        cnta[0][c] = cnta[0][c - 1] + (G[0][c] == 'a');
    }
    for (int r = 1; r < n; r++) {
        cnta[r][0] = cnta[r - 1][0] + (G[r][0] == 'a');
    }
    for (int r = 1; r < n; r++) {
        for (int c = 1; c < n; c++) {
            int val = (G[r][c] == 'a');
            if (r - 1 >= 0) {
                cnta[r][c] = max(cnta[r][c], cnta[r - 1][c] + val);
            }
            if (c - 1 >= 0) {
                cnta[r][c] = max(cnta[r][c], cnta[r][c - 1] + val);
            }
        }
    }
    int prefixLen = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            int dis = r + c + 1;
            if (dis <= k + cnta[r][c]) prefixLen = max(prefixLen, dis);
        }
    }
    queue<pii> que;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            int dis = r + c + 1;
            if (dis == prefixLen && k + cnta[r][c] >= dis) {
                //cout << r << " " << c << endl;
                que.push({r, c});
                vis[r][c] = 1;
            }
        }
    }
    string ans;
    if (que.empty()) {
        ans += G[0][0];
        que.push({0, 0});
        vis[0][0] = 1;
    }
    for (int i = 0; i < prefixLen; i++) ans += 'a';
    while (!que.empty()) {
        unordered_map<char, vector<pii>> mp;
        while (!que.empty()) {
            auto [r, c] = que.front();
            que.pop();
            if (r + 1 < n) {
                mp[G[r + 1][c]].emplace_back(r + 1, c);
            }
            if (c + 1 < n) {
                mp[G[r][c + 1]].emplace_back(r, c + 1);
            }
        }
        for (char c = 'a'; c <= 'z'; c++) {
            if (mp.find(c) != mp.end()) {
                for (auto& [x, y] : mp[c]) {
                    if (!vis[x][y]) {
                        vis[x][y] = 1;
                        que.push({x, y});
                    }
                }
                ans += c;
                break;
            }
        }
    }
    cout << ans << "\n";
}
