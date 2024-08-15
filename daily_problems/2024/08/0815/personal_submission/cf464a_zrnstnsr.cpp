#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;

void solve() {
    int n, p; cin >> n >> p;
    string s; cin >> s;
    if (p == 1) cout << "NO\n";
    else if (p == 2) {
        if (s == "a") cout << "b\n";
        else if (s == "ab") cout << "ba\n";
        else cout << "NO\n";
    } else {
        int i = n - 1;
        char c = s[i];
        while (i > 0) {
            while (++c == s[i-1] || (i > 1 && c == s[i-2]));
            if (c < 'a' + p) break;
            c = s[--i];
        }
        if (!i && ++c == 'a' + p) cout << "NO\n";
        else {
            s[i] = c;
            string t = i > 0 ? s.substr(i - 1, 2) : "0" + s.substr(i, 1);
            for (int j = 1; j < 4; ++j) {
                c = 'a';
                while (c == t[j-1] || c == t[j]) ++c;
                t += c;
            }
            t = t.substr(2);
            for (int j = i + 1; j < n; ++j) s[j] = t[(j-i-1)%3];
            cout << s << '\n';
        }
    }
}

int main() {
    int T;
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // cin >> T;
    T = 1;
    while (T--) {
        solve();
    }
    return 0;
}
