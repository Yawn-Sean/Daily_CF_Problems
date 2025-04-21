#include <bits/stdc++.h>
 
using namespace std;

int main() {
    int n;
    cin >> n;
    map<string, int> mp;
    mp["void"] = 0;
    auto parse = [&] (string expr) -> int {
        int m = expr.length();
        int deref = 0, ptr = 0;
        int i = 0;
        for (; i < m; i++) {
            if (expr[i] != '&') break;
            deref += 1;
        }
        string var;
        for (; i < m; i++) {
            if (expr[i] == '*') break;
            var += expr[i];
        }
        ptr = m - i;
        if (mp.find(var) == mp.end()) return -1;
        int t = mp[var];
        if (t < 0 || t + ptr < deref) {
            return -1;
        }
        return t + ptr - deref;
    };
    for (int i = 0; i < n; i++) {
        string st, expr, var;
        cin >> st;
        if (st == "typedef") {
            cin >> expr >> var;
            mp[var] = parse(expr);
        } else {
            cin >> expr;
            int t = parse(expr);
            if (t < 0) {
                cout << "errtype\n";
            } else {
                cout << "void" << string(t, '*') << "\n";
            }
        }
    }
    return 0;
}

