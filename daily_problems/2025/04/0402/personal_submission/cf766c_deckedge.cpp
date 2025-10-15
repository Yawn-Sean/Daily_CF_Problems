#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define ve vector
#define all(x) (x).begin(), (x).end()
#define rep(i, a, b) for (int i = a; i < b; i++)
#define per(i, a, b) for (int i = a; i >= b; i--)

using i64 = long long;
using pi = pair<int, int>;

inline int read() {
    int x;
    cin >> x;
    return x;
}

void solve() {
    int n = read();
    const int inf = 1e9 + 7, mod = 1e9 + 7;
    string str;
    cin >> str;
    vector<int> a(26), b(n);
    generate(all(a), read);
    rep(i, 0, n) {
        b[i] = a[str[i] - 'a'];
    }
    vector<i64> dp(n + 1, 0);
    vector<int> len(n + 1, 0), cnt(n + 1, inf);
    dp[0] = 1, cnt[0] = 0;
    rep(i, 1, n + 1) {
        int cur = inf;
        per(j, i - 1, 0) {
            int k = i - j;
            cur = min(cur, b[j]);
            if (k > cur) {
                break;
            }
            dp[i] = (dp[i] + dp[j]) % mod;
            len[i] = max(len[i], max(len[j], k));
            cnt[i] = min(cnt[i], cnt[j] + 1);
        }
    }
    cout << dp[n] % mod << '\n';
    cout << len[n] << '\n';
    cout << cnt[n] << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    while (t--) {
        solve();
    }

    return 0;
}