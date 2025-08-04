#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6 + 10; 
const int mod = 998244353;
void solve()
{
    int n;cin>>n;vector<int> a(n+1), b(n+1);int all = 0;
    for(int i = 1; i <= n; i++)cin >> a[i], all+= a[i];
    vector<int> mi(n+1);
    for(int i = 1; i <= n; i++)b[i] = b[i-1] - 2 * a[i], mi[i] = max(mi[i-1], b[i]);
    int ans = mi[n] + all, sum = 0;
    for(int i = n; i >= 1; i --){
        sum -= 2*a[i];
        ans = max(ans, all + sum + mi[i-1]);
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
