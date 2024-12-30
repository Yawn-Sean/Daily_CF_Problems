#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
int mod = 1e9 + 7;
int a[1010];
ll memo[1010][1010];
void solve() {
    for (int i = 2; i <= 1000; i++) {
        a[i] = a[__builtin_popcount(i)] + 1;
    }
    string s;
    cin >> s;
    int k;
    cin >> k;
    int n = s.size();
    if (k == 0) {
        cout << 1 << endl;
        return;
    } else if (k == 1) {
        cout << n - 1 << endl;
        return;
    }
    memset(memo, -1, sizeof(memo));
    function<int(int, int, int)> dfs = [&](int pos, int cnt, bool limit) -> int {
        if (pos == n) return a[cnt] + 1 == k;
        if (!limit && memo[pos][cnt] != -1) return memo[pos][cnt];
        // 填0
        ll ans = dfs(pos + 1, cnt, limit && s[pos] == '0') % mod;
        // 填1
        if (!limit || s[pos] == '1')
            ans = (ans + dfs(pos + 1, cnt + 1, limit && s[pos] == '1')) % mod;
        return memo[pos][cnt] = ans % mod;
    };
    cout << dfs(0, 0, true) << endl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}