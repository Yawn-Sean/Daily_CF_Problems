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
    int n;
    cin >> n;
    int l = 1, r = 1e18;
    auto check = [&](int x)->int{
        int ans = 0;
        while(x){
            ans += x;
            x /= 10;
        }
        return ans;
    };
    while(l < r){
        int mid = (l + r) / 2 + 1;
        if(check(mid) <= n)l = mid;
        else r = mid-1;
    }
    cout <<n - l << '\n';
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
