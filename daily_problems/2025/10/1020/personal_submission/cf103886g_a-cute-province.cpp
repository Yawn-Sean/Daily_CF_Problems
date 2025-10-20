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
const int N = 1e7 + 10;
void solve()
{
    int n;
    cin >> n;
    auto f = [&](auto &f, int x)->vector<int>{
        if(x == 1)return {1};
        vector<int> ans;
        for(auto &u : f(f, x/2))ans.emplace_back(2*u);
        for(auto &u : f(f, (x+1)/2))ans.emplace_back(2*u-1);
        return ans;
    };
    for(auto &x : f(f, n))cout << x << ' ';

    
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
