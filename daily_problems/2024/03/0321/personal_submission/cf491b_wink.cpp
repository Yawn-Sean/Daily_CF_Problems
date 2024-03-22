#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
#define sz(s) ((int)s.size())
#define ms(s, x) memset(s, x, sizeof(s))
const int inf = 0x3f3f3f3f;
const int mod = 1000000007;
const int N = 200010;

// 绝对值不等式拆开
void solve()
{
    int n, m, c;
    cin >> n >> m >> c;

    ll mi_x = 1e18, ma_x = -1e18;
    ll mi_y = 1e18, ma_y = -1e18;

    for (int i = 0; i < c; ++i)
    {
        ll x, y;
        cin >> x >> y;
        mi_x = min(mi_x, x + y);
        ma_x = max(ma_x, x + y);
        mi_y = min(mi_y, x - y);
        ma_y = max(ma_y, x - y);
    }

    ll ans = 1e18;
    int idx = 0;
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i)
    {
        ll x, y;
        cin >> x >> y;

        ll d = max({x + y - mi_x, ma_x - x - y, x - y - mi_y, ma_y - x + y});
        if (d < ans)
        {
            ans = d;
            idx = i + 1;
        }
    }

    cout << ans << '\n';
    cout << idx << '\n';
}
int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cout << setiosflags(ios::fixed) << setprecision(2);
    int t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
