/*
维护以 0 结尾和以 1 结尾的序列编号
假设 s0 为当前所有以 0 结尾的序列编号，s1 为当前所有以 1 结尾的序列编号
假如下一个数 a[i] = 0，则从 s1 中选一个编号出来，把 0 接到这个后面，然后把这个编号放到 s0 中
倘若 s1 为空，则需要新开一个序列放到 s0 中
假如下一个数 a[i] = 1，则从 s0 中选一个编号出来，把 1 接到后面，放到 s1 中
倘若 s0 为空，则寄了
最后 s1 必须为空
*/

int T;

void solve1() {
    int n;
    string s;
    cin >> s;
    n = s.size();
    s = " " + s;
    stack<int> s0, s1;
    int idx = 0;
    vector<int> res(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (s[i] == '0') {
            if (!s1.empty()) {
                int id = s1.top();
                s1.pop();
                res[i] = id;
                s0.push(id);
            } else {
                res[i] = ++idx;
                s0.push(idx);
            }
        } else {
            if (!s0.empty()) {
                int id = s0.top();
                s0.pop();
                res[i] = id;
                s1.push(id);
            } else {
                cout << "-1\n";
                return;
            }
        }
    }
    if (!s1.empty()) {
        cout << "-1\n";
        return;
    }
    vector<vector<int>> groups(n + 1);
    for (int i = 1; i <= n; i++) {
        groups[res[i]].pb(i);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (groups[i].size() > 0) {
            cnt++;
        }
    }
    cout << cnt << "\n";
    for (int i = 1; i <= n; i++) {
        if (groups[i].size() > 0) {
            cout << groups[i].size() << " ";
            for (auto &id : groups[i]) {
                cout << id << " ";
            }
            cout << "\n";
        }
    }
}          
