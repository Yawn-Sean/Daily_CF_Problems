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
const int N = 1e6 + 10;
void solve()
{
   int n;
   cin >> n;
   vector<int> a(n);
   for(auto & x : a)cin >> x;
   int mi = *min_element(a.begin(), a.end()), ma = *max_element(a.begin(), a.end());
   if(mi == ma){
    cout << (int)pow(10, n) << '\n';
    return ;
   }
   int ans = 1;
   for(auto x : a){
    if(x == ma)ans *= (10-x+1);
    else if(x == mi)ans *= (x);
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
