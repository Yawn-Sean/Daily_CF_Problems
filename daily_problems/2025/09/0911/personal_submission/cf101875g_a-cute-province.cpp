#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 2e5+10; 
const int mod = 1e9 + 7;
void solve()
{
   int n;
   cin >> n;
   vector<PII> ve;
   for(int i = 1; i <=n; i++){
    int v, s;
    cin >> s >> v;
    ve.emplace_back(s, v);
   }
   sort(ve.rbegin(), ve.rend());
   stack<PII> stk;
   double ans = 0;
   for(auto [s, v] : ve){
   	if(stk.empty()){
   		stk.push({s, v});
   		continue;
	   }
    if(v > stk.top().y){
        ans = max(ans, (double)(stk.top().x - s)/(v - stk.top().y));
    }
    else{
        stk = {};
        stk.push({s, v});
    }
   }
   cout << fixed << setprecision(6) << ans << '\n';
}       
signed cute_prov0nce()
{
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
