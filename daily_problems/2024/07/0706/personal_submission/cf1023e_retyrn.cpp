int n;

bool ask(int x1, int y1, int x2, int y2) {
    cout << '?' << ' ' << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
    cout.flush();
    string s;
    cin >> s;
    return s[0] == 'Y';
}

void solve() {
    cin >> n;
    
    int x = 1, y = 1;
    string res;
    for (int i = 0; i < n - 1; i ++) {
        if (ask(x, y + 1, n, n)) {
            y += 1;
            res.push_back('R');
        }
        else {
            x += 1;
            res.push_back('D');
        }
    }
    
    x = n, y = n;
    string res1;
    for (int i = 0; i < n - 1; i ++) {
        if (ask(1, 1, x - 1, y)) {
            x -= 1;
            res1.push_back('D');
        }
        else {
            y -= 1;
            res1.push_back('R');
        }
    }
    reverse(all(res1));
    
    res += res1;
    
    cout << "! " << res << endl;
    cout.flush();
}