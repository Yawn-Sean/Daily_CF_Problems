#include <bits/stdc++.h>
using namespace std;

#define endl '\n'
#define rep(i, a, b) for (int i = a; i <= b; ++i)
#define erp(i, a, b) for (int i = a; i >= b; --i)

using i64 = long long;
using pii = pair<int, int>;
using pll = pair<i64, i64>;

const int mod = 1000000007, mod0 = 998244353;

void solve() {
    string s;
    cin >> s;
    int pos = s.find('.');
    if (pos == -1)
        s += ".0";
    else if (pos == 0)
        s = "0" + s;
    else if (pos == s.size() - 1)
        s += '0';

    int l = 0;
    pos = s.find('.');
    while (l < pos - 1 && s[l] == '0')
        ++l;
    s = s.substr(l);

    pos = s.find('.');
    if (s[0] != '0') {
        s.erase(s.begin() + pos);
        s.insert(s.begin() + 1, '.');
        int r = s.size() - 1;
        while (r > 1 && s[r] == '0')
            --r;
        s = s.substr(0, r + 1);
        int b = pos - 1;
        if (r == 1)
            s.erase(s.end() - 1);
        if (b != 0)
            s += "E" + to_string(b);
        cout << s << endl;
        return;
    }
    int n = s.size(), b = 1;
    l = pos + 1;
    while (l < n - 1 && s[l] == '0') {
        ++b;
        ++l;
    }
    int r = n - 1;
    while (r > l && s[r] == '0')
        --r;
    s = s.substr(l, r - l + 1);
    s.insert(s.begin() + 1, '.');
    if (s.back() == '.')
        s.erase(s.end() - 1);
    cout << s << "E-" << b << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
