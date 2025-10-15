#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e2; 
const int mod = 1e9 + 7;

void solve()
{
   int n, m, k;
   cin >> n >>m>>k;
   vector<int> a(n+1), b(m+1), w(n+1);
   for(int i = 1; i <= n ;i ++)cin >> a[i], w[a[i]] = i;
   for(int i = 1; i <= m; i ++)cin >> b[i];
    int ans = 0 ;
    for(int i  =1; i <= m; i++){
       
        ans += (w[b[i]] + k-1)/k;
        if(w[b[i]] > 1)swap(a[w[b[i]]], a[w[b[i]]-1]);
        w[a[w[b[i]]]]++;
        w[b[i]]--;
        
    }
    cout << ans << '\n';
}
signed cute_prov0nce()
{
     ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
     // 取消同步流
     int t;
     //cin >> t;
     t = 1;
     while (t--)
     {
          solve();
     }

     return 0;
}
