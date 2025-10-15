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
    int n,m;
    cin>>n>>m;
    vector<PII> v;
    for(int i = 1; i <= m; i++){
        int d, h;
        cin >>d >>h;
        v.emplace_back(d, h);
    }
    int ans = max(v.front().y + v.front().x-1, v.back().y + n - v.back().x);
    for(int i = 0; i < m-1; i ++){
        int h1 = v[i].y, h2 = v[i+1].y, d = v[i+1].x - v[i].x;
        ans = max(ans, (d+h1+h2)/2);
        if(abs(h1-h2) > d){
            cout << "IMPOSSIBLE" << '\n';
            return ;
        }
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
