#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>
#define ctzll(x) __builtin_ctzll(x)
#define popcount(x) __builtin_popcount(x)

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, ans = 0;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i) {
        int x = 0;
        string s;
        cin >> s;
        for (char c : s) {
            x ^= (1 << (c - 'a'));
        }
        ans += mp[x];
        for (int j = 0; j < 26; ++j) {
            ans += mp[x ^ (1 << j)];
        }
        ++mp[x];
    }
    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
