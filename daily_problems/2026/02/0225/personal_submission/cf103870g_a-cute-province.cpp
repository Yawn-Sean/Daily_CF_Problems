#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 2e5 + 10;
void solve()
{
    int a, b, m;
    cin >> a >> b >> m;
    int p = 1, ans = 0;
    for(int i = 1; i <= 30; i ++){
        p *= 2;
        if((p-1) >= m){
            ans += floor((b-(p/2)+1)*1.0/p) - (a + p/2)/p + 1;
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
    //t = 1; 
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
