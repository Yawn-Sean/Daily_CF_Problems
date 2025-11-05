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
const int N = 1e6 + 10;
const double pi = acosl(-1);
void solve()
{
   int m, t;
   cin >> m >> t;
   int l = 3, r = t/m;
   if(l > r){
    cout << 0 << '\n';
    return ;
   }
   auto calc = [&](int k)-> double{
    return 1.0*(t-k*m)*(t-k*m) / (4.0 * k *tan(pi/k));
   };
   while(l < r){
    int midl = l + (r-l+1)/3;
    int midr = l + (r-l+1)*2/3;
    if(calc(midl) > calc(midr))r = midr -1;
    else l = midl + 1;
   }

cout <<fixed << setprecision(10) << calc(l) << '\n';
   
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
