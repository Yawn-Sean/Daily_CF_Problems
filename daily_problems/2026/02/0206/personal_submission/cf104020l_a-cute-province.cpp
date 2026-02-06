#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
using namespace std;
#define int long long
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 1e5 + 10;
void solve()
{
    int n;
    cin >> n;
    long double ans = 1e18;
    vector<array<int, 3>> v;
    for(int i = 1; i <= n; i ++){
        int x, y, z;
        cin >> x >> y >> z;
        v.push_back({x, y, z});
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < n; i ++){
        for(int j = max(0ll, i-100); j < i; j ++){
            int dx = abs(v[i][0] - v[j][0]);
            int dy = abs(v[i][1] - v[j][1]);
            int dz = abs(v[i][2] - v[j][2]);
            ans = min(ans,  sqrtl(dx*dx + dy*dy + dz*dz));
        }
    }
    cout << fixed << setprecision(6) << ans << '\n';
    
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
