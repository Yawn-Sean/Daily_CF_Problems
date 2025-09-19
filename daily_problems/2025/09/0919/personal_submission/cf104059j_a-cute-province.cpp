#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6+10;
const int mod = 998244353;
void solve()
{
    string s;
    cin >> s;
    string a = "cdhs";
    vector<string> ve;
    do {
        ve.emplace_back(a);
    }while (next_permutation(a.begin(), a.end()));
    int ans = s.size();
    for (auto &x : ve) {
        vector<int> dp(4);
        for (int i = 0 ; i < s.size(); i ++) {
            for (int j = 0; j < 4; j ++) {
                if (x[j] == s[i]) {
                    dp[j] = dp[j] + 1;
                    if (j > 0)dp[j] = max(dp[j], dp[j-1] + 1);
                }
            }
        }
        for (int i = 0 ; i < 4; i ++)
        ans = min(ans, (int)s.size() - dp[i]);
    }
    cout << ans << '\n';

}
signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int T;
    //cin >> t;
    T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}
