#include<bits/stdc++.h>
using namespace std;
#define pii pair<int, int>
#define pdd pair<double, double>
#define pll pair<ll, ll>
#define debug(x) cerr << #x << ": " << x << '\n';
#define endl '\n'
typedef long long ll;
typedef unsigned long long ull;
inline void solve()
{
    int n, U, r;
    cin >> n >> U >> r;
    vector<ll> a(n+1), b(n+1), k(n+1), p(n+1);
    for(int i=1; i<=n; i++)
        cin >> a[i];
    for(int i=1; i<=n; i++)
        cin >> b[i];
    for(int i=1; i<=n; i++)
        cin >> k[i];
    for(int i=1; i<=n; i++)
        cin >> p[i];
    ll res = -2e18;
    function<void(int, int, vector<ll>)> dfs = [&](int u, bool flg, vector<ll> t) {
        if((U - u) % 2 == 0) {
            ll tot = 0;
            for(int i=1; i<=n; i++) {
                tot += t[i] * k[i];
            }
            res = max(res, tot);
        }
        if(u == U) {
            return;
        }
        if(!flg) {
            auto tt = t;
            for(int i=1; i<=n; i++) {
                tt[i] ^= b[i];
            }
            dfs(u+1, 1, tt);
            tt = t;
            for(int i=1; i<=n; i++) {
                tt[i] = t[p[i]] + r;
            }
            dfs(u+1, 0, tt);
        } else {
            auto tt = t;
            for(int i=1; i<=n; i++) {
                tt[i] = t[p[i]] + r;
            }
            dfs(u+1, 0, tt);
        }
    };
    dfs(0, 0, a);
    cout << res << endl;
}
int main()
{
    cout << fixed << setprecision(10);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    int t;
    t = 1;
    while(t --)
        solve();
    return 0;
}
