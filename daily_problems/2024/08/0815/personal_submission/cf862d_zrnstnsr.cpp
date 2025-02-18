#include <bits/stdc++.h>
using namespace std;

using ll = long long;
constexpr int mod = 1000000007;
constexpr int inf = 0x3f3f3f3f;

void solve() {
    int n;
    cin >> n;
    string s(n, '0');
    cout << "? " << s << endl;
    int u; cin >> u;
    int l = 0, r = n;
    int pos0 = 0, pos1 = 0;
    while (!pos0 || !pos1) {
        int m = l + (r - l) / 2;
        int zero, one;
        if (s[m] == '0') {
            for (int i = m; i < r; ++i) s[i] = '1';
            zero = r - m;
            one = m - r;
        } else {
            for (int i = m; i < r; ++i) s[i] = '0';
            zero = m - r;
            one = r - m;
        }
        cout << "? " << s << endl;
        int v; cin >> v;
        int d = v - u;
        if (d == zero) {
            pos0 = r;
            r = m;
        } else if (d == one) {
            pos1 = r;
            r = m;
        } else {
            l = m;
        }
        u = v;
    }
    cout << "! " << pos0 << " " << pos1 << endl;
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
