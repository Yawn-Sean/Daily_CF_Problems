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
   int n, m, k;
   cin >> n >> m  >> k;
   vector<int> a(n+1), d(m+1), f(k);
   for(int i = 1; i  <= n; i++)cin >> a[i];
   for(int i  =1; i <= m; i ++)cin>> d[i];
   for(int i  =0; i < k; i ++){
    cin >> f[i];
   }
   vector<PII> v;
   for(int i = 2; i <= n; i++)v.emplace_back(a[i]-a[i-1], i-1);
   sort(v.begin(), v.end());
   sort(f.begin(), f.end());
   if(v.size() > 1 && (*v.rbegin()).x == (*--(--v.end())).x){
        cout << v.back().x << '\n';
        return ;
   }
   
   int ans = v.back().x;
   int U = a[v.back().y], V = a[v.back().y] + v.back().x;
   int flag = U + V >> 1;
   for(int i  =1; i <= m; i ++){
        int w = lower_bound(all(f), flag-d[i])-f.begin();
        if(w && f[w-1] + d[i] >= U && f[w-1] + d[i] <= V)ans = min(ans, max(f[w-1] + d[i]-U, V - (f[w-1] + d[i])));
        if(w != f.size() && f[w] + d[i] >= U && f[w] + d[i] <= V)ans = min(ans, max(f[w] + d[i]-U, V - (f[w] + d[i])));
   }   
   if(v.size() > 1)
   cout << max(ans, (*--(--v.end())).x) << '\n';
  else cout << ans << '\n';
}
signed cute_prov0nce()
{   
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     // 取消同步流
     int t;
     cin >> t;
     //t = 1;
     while (t--)
     {
          solve();
     }

     return 0;
}
