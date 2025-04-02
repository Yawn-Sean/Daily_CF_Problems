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
    int n;
    cin >> n;
    string s;
    cin >> s;
    s = '@' + s;
    vector<int> c(26, 0);
    rep (i, 0, 25)
        cin >> c[i];
    vector<int> f(n + 1, 0), f0(n + 1, INT_MAX);
    f[0] = 1, f0[0] = 0;
    int mx_len = INT_MIN;
    rep (i, 1, n) {
        int mx_len0 = INT_MAX;
        erp (j, i, 1) {
            int id = s[j] - 'a';
            int len = i - j + 1;
            mx_len0 = min(mx_len0, c[id]);
            if (mx_len0 < len)
                break;
            f[i] = (f[i] + f[j - 1]) % mod;
            f0[i] = min(f0[j - 1] + 1, f0[i]);
            if (f[j - 1])
                mx_len = max(mx_len, len);
        }
    }
    cout << f[n] << endl;
    cout << mx_len << endl;
    cout << f0[n] << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
