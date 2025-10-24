#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  1e5 + 3;
const int N = 2e3 + 10;

void solve()
{   
    int h, w;
    cin >> h >> w;
    vector<vector<char>> g(h+1, vector<char> (w+1));
    int sum = 0;
    for(int i = 1; i <= h; i ++){
        for(int j = 1; j <= w; j ++)cin >> g[i][j], sum += (g[i][j] == '#');
    }
    auto check = [&](int k)->bool{
        vector<vector<int>> vis(h+1, vector<int>(w+1));
        for(int i = 1; i <= h; i ++){
            for(int j = 1; j <= w; j ++){
                if(vis[i][j] || g[i][j] == '.')continue;
                for(int r = i; r < i + k; r ++){
                    for(int c = j; c < j + k; c ++){
                        if( r > h || c > w || vis[r][c] || g[r][c] == '.' ){
                            return false;
                        }
                        vis[r][c] = 1;
                    }
                }
            }
        }
        return true;
    };
    vector<int> ve;
    for(int i = min(w, h); i >= 1; i --){
        if(sum % i == 0){
            ve.emplace_back(i);
        }
    }
    for(auto u : ve){
        if(check(u)){
            cout << u << '\n';
            return ;
        }
    }
}   

signed cute_prov0nce()
{
#ifdef ACM_LOCAL
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
#endif
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    t = 1;
    //cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
