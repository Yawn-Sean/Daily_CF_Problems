int k;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};

void solve() {
    cin >> k;
    if (k & 1) {
        cout << -1 << endl;
        return;
    }
    vector<string> g(k, string(k, '#'));
    vector<string> g1(k, string(k, '#'));
    int x = 0, y = 0, p = 0;
    char c1 = 'b', c2 = 'w';
    
    auto check = [&g](int x, int y) -> bool {
        if (x < 0 or y < 0 or x >= k or y >= k) return false;
        return g[x][y] == '#';
    };
    
    for (int i = 0; i < k * k; i ++) {
        g[x][y] = c1;
        g1[x][y] = c2;

        if (!check(x + dx[p], y + dy[p])) {
            p = (p + 1) % 4;
        }
        x += dx[p];
        y += dy[p];
        if (x == y and x < k / 2) swap(c1, c2);
    }
    
    for (int i = 0; i < k; i ++) {
        if (i & 1) {
            for (auto& s : g1) {
                cout << s << endl;
            }
        }
        else {
            for (auto& s : g) {
                cout << s << endl;
            }
        }
        cout << endl;
    }
    
}