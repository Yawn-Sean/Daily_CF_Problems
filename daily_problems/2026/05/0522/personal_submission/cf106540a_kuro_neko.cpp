#include <bits/stdc++.h>
#define endl '\n'
#define ll long long
#define ull unsigned long long
#define lowbit(x) (x & (-x))
#define rep(i, x, y) for (int i = x; i <= y; i++)
#define frep(i, x, y) for (int i = x; i >= y; i--)
#define all(x) (x).begin(), (x).end()
#define all2(x) (x).rbegin(), (x).rend()
#define sz(a) (int)a.size()
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tri tuple<int, int, int>
#define trl tuple<ll, ll, ll>
#define vi vector<int>
#define vl vector<ll>
#define vvi vector<vector<int>>
#define vvl vector<vector<ll>>
#define pq priority_queue
#define umap unordered_map
#define mset multiset
using namespace std;
const ll MOD = 998244353;
void solve() {
    int n, k;
    string s;
    cin >> n >> k >> s;
    auto kmp = [&](const string& pattern) -> vi {
        int m = sz(pattern);
        int cnt = 0;
        vi pi(m);
        rep(i, 1, m - 1) {
            char b = pattern[i];
            while (cnt && pattern[cnt] != b) cnt = pi[cnt - 1];
            if (pattern[cnt] == b) cnt++;
            pi[i] = cnt;
        }
        return pi;
    };
    vi pi = kmp(s);
    vvi trans(n + 1, vi(26));
    rep(i, 0, n) {
        rep(j, 0, 25) {
            int tem = i;
            if (i == n) tem = pi[tem - 1];
            while (tem && s[tem] != (char)('a' + j)) tem = pi[tem - 1];
            if (s[tem] == (char)('a' + j)) tem++;
            trans[i][j] = tem;
        }
    }
    vvi dp(k + 1, vi(n + 1, 0));
    dp[0][0] = 1;
    rep(i, 0, k - 1) {
        rep(j, 0, n) {
            if (!dp[i][j]) continue;
            rep(v, 0, 25) {
                int tem = trans[j][v];
                if (tem == 0) continue;
                dp[i + 1][tem] = (dp[i + 1][tem] + dp[i][j]) % MOD;
            }
        }
    }
    ll ans = 0;
    rep(i, 1, n) ans = (ans + dp[k][i]) % MOD;
    cout << ans << endl;
    return;
}
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
