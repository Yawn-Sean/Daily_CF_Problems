int n;
string s;

void solve() {
    cin >> s;
    n = sz(s);
    string s1;
    for (int i = 0; i < n; i ++) {
        if (i + 1 < n and s[i] == '(' and s[i + 1] == ')') s1 += '0', i += 1;
        else if (i + 1 < n and s[i] == '-') s1 += ',', i += 1;
        else {
            s1 += s[i];
        }
    }
    s = s1;
    
    vector<int> num;
    vector<char> op;
    
    n = sz(s);
    for (auto c : s) {
        if (c == '0') num.pbk(0);
        else if (c == ',') op.pbk(',');
        else if (c == '(') op.pbk('(');
        else {
            // ')'
            while (!em(op) and op.back() == ',') {
                auto a = num.back();
                num.pop_back();
                auto b = num.back();
                num.pop_back();
                num.pbk(max(a, b + 1));
                op.pop_back();
            }
            // pop (
            op.pop_back();
        }
    }

    while (!em(op)) {
        auto a = num.back();
        num.pop_back();
        auto b = num.back();
        num.pop_back();
        num.pbk(max(a, b + 1));
        op.pop_back();
    }
    cout << num.back() << endl;
}