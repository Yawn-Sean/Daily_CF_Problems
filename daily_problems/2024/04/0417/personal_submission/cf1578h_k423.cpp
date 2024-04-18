// https://codeforces.com/contest/1578/submission/256987799

/* 我永远喜欢爱莉希雅♪ */
void elysia() {
    string s;
    cin >> s;
    auto help = [](vector<int> &a) {
        int x = -1;
        for (int y: a | views::reverse) {
            x = x == -1 ? y : max(x, y + 1);
        }
        return max(x, 0);
    };
 
    vector<vector<int>> stk(1, vector<int>());
    for (int i = 0, n = s.size(); i < n; ++i) {
        if (s[i] == '(') stk.emplace_back(vector<int>());
        else if (s[i] == ')') {
            int x = help(stk.back());
            stk.pop_back();
            stk.back().emplace_back(x);
        } else {
            assert(s[i] == '-');
            i++;
        }
    }
    cout << help(stk[0]) << endl;
}
