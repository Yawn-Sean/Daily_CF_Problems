void Solve() {
    string s;cin >> s;
    int n = s.size();
    vector<int> stk(n + 1);int tot = 0;
    s = '(' + s + ')';
    for (int i = 0;i < s.size();i++) {
        if (s[i] == '(') {
            stk[++tot] = -1;
        }
        else if (s[i] == ')') {
            if (stk[tot] == -1) stk[tot] = 0;
            else {
                int now = 0;
                while (tot > 0) {
                    if (stk[tot] == -1) {
                        stk[tot] = now;
                        break;
                    }
                    else if (stk[tot] == -2) now = max(now, stk[tot - 1] + 1), tot -= 2;
                    else now = stk[tot--];
                }
            }
        }
        else if (s[i] == '>') {
            stk[++tot] = -2;
        }
    }
    cout << stk[tot] << endl;
}
