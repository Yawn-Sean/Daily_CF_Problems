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
    int n, m;
    cin >> n >> m;
    vector<vector<char>> g(n+2, vector<char> (m+2)), a(n+2, vector<char> (m+2));
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j ++)cin >> g[i][j];
    }
    vector<array<int, 3>> ans;
    for(int i = 1; i <= n ;i ++){
        for(int j =1 ;  j<= m; j++){
            a[i][j] = '.';
            if(g[i][j] == '*'){
                int up = 0, down = 0, left = 0, right = 0;
                int l = 0;
                while(g[i-up-1][j] == '*')up++;
                while(g[i+down+1][j] == '*')down++;
                while(g[i][j-left-1] == '*')left++;
                while(g[i][j+right+1] == '*')right++;
                l = min(min(up, down), min(left, right));
                if(l > 0)ans.push_back({i, j, l});
            }
        }
    }
    
    if(!ans.empty())
    for(auto v : ans){
        int x = v[0], y = v[1], l = v[2];
        for(int i = x - l; i <= x + l; i ++)a[i][y] = '*';
        for(int j = y-l; j <= y+l; j ++)a[x][j] = '*';
    }

    int ok = 1;
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++)if(a[i][j] != g[i][j])ok = 0;
    }
    
    if(ok == 0)cout << -1 << '\n';
    else {
        cout << ans.size() <<'\n';
        for(auto v : ans)cout << v[0] <<' ' << v[1] <<' ' << v[2] << '\n';
    }
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
