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
    int n;
    cin >> n;
    vector<int> d(n+1), v(n+1), p(n+1), ans, vis(n+1);
    int now = 0;
    for(int i = 1; i <= n;i ++)cin >> v[i] >> d[i] >> p[i];
    for(int i = 1; i <= n; i++){
        if(!vis[i]){
            int cut = v[i];
            for(int j = i + 1; j <= n; j ++){
                if(!vis[j] && cut > 0){
                    p[j] -=cut--;
                }
            }
            int cur = 0;
            for(int j = i + 1; j <= n; j++){
                p[j] -=cur;
                if(p[j] < 0 && !vis[j]){
                    vis[j] = 1;
                    cur += d[j];
                }
            }
            ans.emplace_back(i);
        }
    }
    cout << ans.size() <<'\n';
    for(auto u : ans)cout << u <<' ';       
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
