#include <bits/stdc++.h>
using namespace std;

unordered_map<string, int> mp;

int gao(string &x) {
    int a = 0, b = 0;
    for (int i = 0; x[i] == '&'; i++) a++;
    for (int i = x.size() - 1; x[i] == '*'; i--) b++;
    x = x.substr(a, x.size() - a - b);
    if (mp.count(x) == 0) return -1;
    else if (mp[x] < 0) return -1;
    else return mp[x] + b - a;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    int n; cin >> n;
    mp["void"] = 0;
    for (int i = 1; i <= n; i++) {
        string op; cin >> op;
        if (op == "typedef") {
            string x, y; cin >> x >> y;
            int t = gao(x);
            if (t < 0) mp[y] = -1;
            else mp[y] = t;
        } else {
            string x; cin >> x;
            int t = gao(x);
            if (t < 0) cout << "errtype\n";
            else {
                cout << "void";
                for (int i = 1; i <= t; i++) cout << "*";
                cout << "\n";
            }
        }
    }
    return 0;
}
