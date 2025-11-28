#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(), x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod = 1e9 + 7;
const int N = 2e5 + 10;

void solve()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n), sum(n);
    for(int i = 0; i < n; i ++)cin >> a[i];
    sort(a.begin() , a.end());
    sum[0] = a[0];
    for(int i = 1 ; i < n; i ++)sum[i] = sum[i-1] + a[i];
    auto check = [&](int k)->bool{
        int ans = 0;
        for(int i = 0 ;i < n; i ++){
            auto w = lower_bound(a.begin(), a.end(), a[i] + k)-a.begin();
            ans += n - w;
        }
        if(ans * 2 >= m)return true;
        else return false;
    };
    int l = 1, r = 1e7+10;
    while(l < r){
        int mid = (l+r)/2+1;
        if(check(mid))l = mid;
        else r = mid -1;
    }
    int cnt = 0, val = l + 1;
    int ans = 0;
    for(int i = 0 ;i < n; i ++){
        auto w = lower_bound(a.begin(), a.end(), a[i] + val)-a.begin();
        ans += 2*(sum[n-1] - sum[w-1] - (n-w) * a[i]);
        cnt += 2*(n-w);
    }
    cout << ans + l * (m - cnt) << '\n'; 
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
     cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
