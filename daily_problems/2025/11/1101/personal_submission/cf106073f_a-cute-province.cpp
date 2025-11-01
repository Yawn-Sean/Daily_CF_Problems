#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod = 1e9 + 7;
const int N = 1e5 + 10;
const int inv2 = (mod+1)/2;
void solve()
{   
    int n,q;
    cin >> n >> q;
    vector<int> x(q+1), sub(q+2), E(n+1);
    for(int i =1 ; i <= q;i ++)cin >> x[i];
    for(int i = q; i >= 1; i --)sub[i] = (sub[i+1] + x[i])%mod *inv2%mod, sub[i] %= mod;
    E[1] = sub[1];
    for(int i = 1; i <= q;  i ++)E[x[i]] += inv2 * sub[i+1]%mod, E[x[i]] %= mod;
    for(int i = 1; i <= n; i ++)cout << E[i] << '\n';

}

signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
