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
const int mod = 1e9 + 7;
void solve()
{
    int n;
    cin >> n;
    map<int, int> cnt;
    vector<int> a(n+1);
    for(int i = 1; i <= n; i++)cin >> a[i], cnt[a[i]]++;
    int ans = cnt[4] * cnt[1] * cnt[3];
    if(cnt[2] >= 2)ans += cnt[2] * (cnt[2]-1) * cnt[4]/2;
    if(cnt[1] >= 2)ans += cnt[1] * (cnt[1]-1) * cnt[2]/2;
    for(int i = 1; i <=n; i++){
        if(a[i] > 2 && a[i] != 4)ans += cnt[2] * cnt[a[i]-2];
        if(a[i] > 4)ans += cnt[4] * cnt[a[i]-4];
    }
    cout << ans *2 << '\n';
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
