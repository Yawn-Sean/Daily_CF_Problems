int n;
string s;

void solve() {
    // 有一个出现两次的
    cin >> s;
    char st = 'A';
    vector<int> cnt(26);
    for (auto c : s) {
        int u = c - 'A';
        cnt[u] ++;
        if (cnt[u] == 2) st = c;
    }
    
    int l = -1, r = -1;
    for (int i = 0; i < 27; i ++) {
        if (s[i] != st) continue;
        if (l == -1) l = i;
        else if (r == -1) r = i;
    }

    if (l + 1 == r) {
        cout << "Impossible" << endl;
        return;
    }
    vector<string> g(2, string(13, '#'));
    int len = (r - l + 1) / 2;
    int j = l;
    for (int i = len - 1; i >= 0; i --) {
        g[0][i] = s[j ++];
    }
    for (int i = 0; j < r; i ++) {
        g[1][i] = s[j ++];
    }
    reverse(all(g[0]));
    reverse(all(g[1]));
    
    int x = 0, y = -1;
    for (int i = 0; i < 13; i ++) {
        if (g[0][i] == '#') y = i;
        else break;
    }
    if (y == -1) x = 1, y = 0;
    
    for (int i = l - 1; i >= 0; i --) {
        g[x][y] = s[i];
        if (x == 0) y --;
        else y ++;
        if (y == -1) x ++, y = 0;
    }
    
    x = 1, y = inf;
    for (int i = 12; i >= 0; i -- ) {
        if (g[1][i] != '#') continue;
        y = i;
        break;
    }
    if (y == inf) x = 0, y = 0;
      
    for (int i = r + 1; i < 27; i ++) {
        g[x][y] = s[i];
        if (x == 1) y --;
        else y ++;
        if (y == -1) x --, y = 0;
    }
    
    cout << g[0] << endl << g[1] << endl;
}