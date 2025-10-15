#include <bits/stdc++.h>
#define x first
#define y second
#define int long long
#define cute_prov0nce main
using namespace std;
typedef pair<int, int> PII;
using i64 = long long;
const int N = 1e6; 
const int mod = 1e9 + 7;

void solve()
{
    int n ,m;
    cin >> n >> m;
    vector<int> p(n+1), id(n+1), v[n+1];
    for(int i = 1; i <= n; i++)cin >> p[i], id[p[i]] = i;
    for(int i = 1; i <= m; i++){
        int l, r;
        cin >> l >> r;
        if(id[r] < id[l])swap(l, r);
        v[id[r]].emplace_back(id[l]);
    }
    int now = 0, ans = 0;
    for(int i = 1 ;i <= n;i++){
        for(auto u : v[i]){
            now = max(now, u);
        }
        ans += i - now ;
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
