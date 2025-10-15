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
   vector<int> pre(n+1), a(n+1);
   vector<PII> v, ans(n+1);
   for(int i =1 ; i <= n; i++)cin >> a[i];
   for(int i =2 ; i <=n ; i ++)
    v.emplace_back(a[i], i);
   sort(v.rbegin(), v.rend());
   int x = 1,y = 1;
   ans[1] = {1, 1};
   pre[1] = 1;
   for(int i = 0; i < n-1; i++){
    if(v[i].x == 0)x++;
    else if(v[i].x-1 + y <= n )x ++, y = v[i].x-1 + y;
    else x ++, y = y - v[i].x+1;
    ans[v[i].y] = {x, y}; 
    if(v[i].x == 0)pre[v[i].y] = v[i].y;
    else if(i == 0)pre[v[i].y] = 1;
    else pre[v[i].y] = v[i-1].y;
   }
   cout << "YES" << '\n';
   for(int i = 1; i <=n ;i++)cout << ans[i].x <<' ' << ans[i].y << '\n';
   for(int i =1; i <= n; i++)cout << pre[i] << ' ';

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
