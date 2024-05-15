void Solve() {
    int n;cin >> n;
    vector<string> s(n + 1);s[0] = '0';
    for (int i = 1;i <= n;i++) cin >> s[i];
    auto suan = [&](string pre, string now) {
        if (pre.size() < now.size()) {
            for (int i = 0;i < now.size();i++) {
                if (now[i] == '?') {
                    if (i) now[i] = '0';
                    else now[i] = '1';
                }
            }
        }
        else {
            int ptr = now.size();
            for (int i = 0;i < now.size();i++) {
                if (now[i] != '?' && now[i] != pre[i]) {
                    if (now[i] > pre[i]) {
                        for (int j = 0;j < i;j++) {
                            if (now[j] == '?') now[j] = pre[j];
                        }
                        for (int j = i + 1;j < now.size();j++) {
                            if (now[j] == '?') now[j] = '0';
                        }
                        return now;
                    }
                    else {
                        ptr = i;
                        break;
                    }
                }
            }
            vector<int> cun;
            for (int j = 0;j < ptr;j++) {
                if (now[j] == '?') cun.push_back(j);
            }
            auto dfs = [&](auto&& dfs, int pos)->ll {
                if (pos == cun.size()) {
                    return 1;
                }
                int flag = dfs(dfs, pos + 1);
                int u = cun[pos];
                if (pre[u] - '0' + flag >= 10) {
                    now[u] = pre[u] + flag - 10;
                    return 1;
                }
                else {
                    now[u] = pre[u] + flag;
                    return 0;
                }
                };
            if (dfs(dfs, 0)) {
                cout << "NO" << endl;
                exit(0);
            }
            for (int j = ptr + 1;j < now.size();j++) {
                if (now[j] == '?') now[j] = '0';
            }
        }
        return now;
        };
    for (int i = 1;i <= n;i++) {
        if (s[i].size() < s[i - 1].size()) return cout << "NO" << endl, void();
        s[i] = suan(s[i - 1], s[i]);
    }
    cout << "YES" << endl;
    for (int i = 1;i <= n;i++) {
        cout << s[i] << endl;
    }
}
