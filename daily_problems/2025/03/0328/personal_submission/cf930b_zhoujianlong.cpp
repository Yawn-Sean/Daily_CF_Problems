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
    int n = s.size();
    s = '@' + s;
    map<char, vector<int>> mp;
    rep (i, 1, n)
        mp[s[i]].push_back(i);

    double ans = 0;
    for (auto &[c, vec] : mp) {
        int mx_cnt = 0;
        rep (i, 0, n - 1) {
            map<char, int> cnt0;
            for (auto &pos : vec) {
                int i0 = (pos + i) % n + 1;
                cnt0[s[i0]]++;
            }
            int cnt = 0;
            for (auto &[_, v] : cnt0)
                cnt += v == 1;
            mx_cnt = max(mx_cnt, cnt);
        }
        ans += mx_cnt;
    }
    cout << fixed << setprecision(6) << ans * 1.0 / n << endl;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
