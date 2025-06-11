int n;
string s;

int cal(char c) {
    if (c == 'a' or c == 'e' or c == 'i' or c == 'o' or c == 'u') return -1;
    return 2;
}
void solve() {
    cin >> s;
    n = sz(s);
    for (auto& c : s) {
        if (c >= 'A' and c <= 'Z') {
            c += 'a' - 'A';
        }
    }
    
    // 1个辅音算2 1个元音算-1 >= 0的前缀
    
    // [-n, n*2]
    Fenwick<int> fen(n * 3 + 1);
    int len = 0, cnt = 0;
    vector<int> seen(n * 3 + 1, false);
    
    fen.add(n, 0);
    seen[n] = true;
    
    int cur = 0;
    for (int i = 0; i < n; i ++) {
        cur += cal(s[i]);
        int t = fen.sum(cur + n + 1);
        if (i + 1 - t > len) {
            len = i + 1 - t;
            cnt = 1;
        }
        else if (i + 1 - t == len) cnt ++;
        
        if (!seen[cur + n]) {
            seen[cur + n] = true;
            fen.add(cur + n, i + 1);
        }
    }
    if (len == 0) {
        cout << "No solution" << endl;
        return;
    }
    cout << len << ' ' << cnt << endl;
}