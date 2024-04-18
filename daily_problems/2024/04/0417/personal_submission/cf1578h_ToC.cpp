// https://codeforces.com/contest/1578/submission/257072905
void sol()
{
    string s;
    cin >> s;
    replaceAll(s, "()", "0");
    replaceAll(s, "->", "^");
    vector<char> opd;
    vector<char> opt;
    for (auto &c : s) {
        if (c == '0') {
            opd.push_back(c);
        } else if (c == '(') {
            opt.push_back(c);
        } else if (c == ')') {
            while (opt.back() != '(') {
                opd.push_back(opt.back());
                opt.pop_back();
            }
            opt.pop_back();
        } else {
            opt.push_back(c);
        }
    }
    while (!opt.empty()) {
        opd.push_back(opt.back());
        opt.pop_back();
    }
    stack<int> stk;
    for (auto &e : opd) {
        if (e == '0') {
            stk.push(0);
        } else {
            int r = stk.top();
            stk.pop();
            int l = stk.top();
            stk.pop();
            stk.push(max(l + 1, r));   
        }
    }
    cout << stk.top() << '\n';
}
