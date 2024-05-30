void Solve() {
    string s;cin >> s;
    int n = s.size();s = ' ' + s;
    vector<array<int, 2>> cun;
    for (int i = 1;i <= n;) {
        int ks = i;
        i++;
        while (i <= n && s[i] == s[i - 1]) i++;
        cun.push_back({ s[ks] - 'a',i - ks });
    }
    int res = 0;
    while (cun.size() > 1) {
        for (int i = 0;i < cun.size();i++) {
            if (i == 0 || i + 1 == cun.size()) cun[i][1]--;
            else cun[i][1] = max(0LL, cun[i][1] - 2);
        }
        vector<array<int, 2>> nc;
        for (int i = 0;i < cun.size();i++) {
            if (cun[i][1]) {
                if (nc.size() == 0) nc.push_back(cun[i]);
                else {
                    if (nc.back().at(0) == cun[i][0]) nc.back().at(1) += cun[i][1];
                    else nc.push_back(cun[i]);
                }
            }
        }
        cun = nc;
        res += 1;
    }
    cout << res << endl;
}
