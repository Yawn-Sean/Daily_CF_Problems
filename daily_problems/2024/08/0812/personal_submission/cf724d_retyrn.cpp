int n, m;
string s;

bool check(char c) {
    vector<int> pos = {-1};
    for (int i = 0; i < n; i ++) {
        if (c < s[i]) continue;
        if (i - pos.back() <= m) {
            pos.push_back(i);
        }
        else return false;
    }
    return n - pos.back() <= m;
}

void solve() {
    cin >> m >> s;
    n = sz(s);
    
    char c = 'a';
    while (c <= 'z' and !check(c)) {
        c += 1;
    }
    
    vector<int> pos = {-1};
    for (int i = 0; i < n; i ++) {
        if (s[i] > c) continue;
        while (pos.back() >= 0 and s[pos.back()] == c and i - pos[sz(pos) - 2] <= m) {
            pos.pop_back();
        }
        if (s[i] < c or n - pos.back() > m) pos.push_back(i);
    }
    
    string res;
    for (auto x : pos) {
        if (x >= 0) res += s[x];
    }
    sort(all(res));
    cout << res << endl;
}