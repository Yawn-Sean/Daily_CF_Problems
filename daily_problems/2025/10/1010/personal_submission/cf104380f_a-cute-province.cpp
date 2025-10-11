#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 3e5+10;
const int mod = 998244353;

void solve() {
    int n, l, r;
    cin >> n >> l >> r;
    vector<int> a(n), ve;
    for(int i = 0 ; i < n; i ++)cin >> a[i];
    for(int i = 0;  i < n - min(l-1, n - r); i ++)ve.emplace_back(a[i]);
    sort(ve.rbegin(), ve.rend());
    int ans = 0;
    for(int i = 0 ; i < r-l+1; i ++)ans += ve[i];
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
    //cin >> t;
    t = 1;
    while (t--)
    {
        solve();
    }
    return 0;
}
