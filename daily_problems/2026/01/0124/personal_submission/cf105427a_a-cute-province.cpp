#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 1e6 + 10;
void solve()
{
    int n, k;
    cin >> n >> k;  
    int cnt0 = 1, cnt1 = 0;
    vector<PII> ve;
    for(int i = 1; i <= k; i ++){     
        cnt0 *= k;
        cnt1 *= k;
        cnt1 ++;
        if(cnt1 + cnt0 > n)break;
        ve.emplace_back(cnt0+cnt1, cnt0);
    }
    int ans = 0;  
    if(ve.size() == k)ans = n - cnt0;
    else{
        int m = (int)ve.size()-1;
        for(int i = m; i >= 0; i --){
            if(ve[i].x <= n){
                int cnt1 = ve[i].x-ve[i].y, cnt0 = ve[i].y;
                int t = n / (cnt1 + cnt0);
                ans += t * cnt1;
                n = n % (cnt1 + cnt0);
            }
        }
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
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
