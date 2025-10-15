PII query(string& s) {
    cout << s << endl;
    PII p;
    cin >> p.first >> p.second;
    if (p.first == 4) exit(0);
    return p;
}

void solve() {
    string ans;
    for (int i = 0; i < 10; i++) {
        string t;
        for (int j = 0; j < 4; j++) {
            t += '0' + i;
        }
        PII p = query(t);
        if (p.first != 0) {
            ans += '0' + i;
        }
        if (ans.size() == 4) {
            break;
        }
    }
    while (true) {
        query(ans);
        next_permutation(ans.begin(), ans.end());
    }
    return;
}