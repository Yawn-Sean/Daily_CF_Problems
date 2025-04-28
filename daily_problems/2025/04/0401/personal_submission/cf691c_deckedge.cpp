void solve() {
    string str;
    cin >> str;
    int pos1 = -1, pos2 = str.size(), pos3  = -1;
    int n = str.size();
    bool found = false;
    rep(i, 0, n) {
        if (str[i] == '.') {
            pos2 = i;
        } else if (str[i] != '0' && !found) {
            pos1 = i;
            found = true;
        }
    }
    per(i, n - 1, 0) {
        if (str[i] != '.' && str[i] != '0') {
            pos3 = i;
            break;
        }
    }
    if (pos1 == -1) {
        cout << "0\n";
        return ;
    }
    string res;
    res += str[pos1];
    rep(i, pos1 + 1, pos3 + 1) {
        if (str[i] == '.') {
            continue;
        }
        res += str[i];
    }
    while (res.back() == '0') {
        res.pop_back();
    }
    if (res.size() > 1) {
        res.insert(1, ".");
    }
    int cnt = 0;
    if (pos2 > pos1) {
        cnt = pos2 - pos1 - 1;
    } else {
        cnt = pos2 - pos1;
    }
    cout << res;
    if (cnt) {
        cout << "E" << cnt;
    }
    cout << '\n';
}
