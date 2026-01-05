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
const int N = 1e6 + 10;
int f[N];
void solve()
{
    int d;
    cin >> d;
    int ans = 0;
    for(int i = 1; i < d; i ++){
        ans += (f[i]-1)* (f[d]-1-(f[i]-1) + mod)%mod * f[d-i]%mod *2 %mod;
        ans %= mod;
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
    int t;
    //t = 1;
    f[0] = 1;
    for(int i = 1; i < N; i ++)f[i] = f[i-1] * 2 %mod;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
