#include <bits/stdc++.h>
#define x first
#define y second
#define cute_prov0nce main
#define int long long
using namespace std;
#define all(x) x.begin(),x.end()
typedef pair<int, int> PII;
using i64 = long long;
const int mod =  998244353;
const int N = 2000 + 10;
PII dx[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}}; 
void solve()
{
    int n, m;
    cin >> n >> m;
    vector<array<int,4>> ans;
    vector<vector<int>> g1(n+5, vector<int> (m+5)), g2(n+5, vector<int> (m+5));
    int sum1 = 0, sum2 = 0;
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            char x;
            cin >> x;
            if(x == '#')g1[i][j] = 1 ^ ((i+j)%2 == 1 ? 1 : 0);
            else g1[i][j] = 0 ^ ((i+j)%2 == 1 ? 1 : 0);
            sum1 += g1[i][j];
        }
    }
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= m; j ++){
            char x;
            cin >> x;
            if(x == '#')g2[i][j] = 1 ^ ((i+j)%2 == 1 ? 1 : 0);
            else g2[i][j] = 0 ^ ((i+j)%2 == 1 ? 1 : 0);
            sum2 += g2[i][j];
        }
    }
    if(sum1 != sum2){
        cout << "-1\n";
    }
    else{
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <=m ;j ++){
                if(g2[i][j] != g1[i][j]){
                    queue<PII> q;
                    vector<vector<PII>> pre(n+5, vector<PII> (m+5));
                    vector<vector<int>> vis(n+5, vector<int> (m+5));


                    q.push({i, j});
                    vis[i][j] = 1;
                    while(!q.empty()){
                        auto [x, y] = q.front(); q.pop();
                        if(g1[x][y] == g2[i][j]){
                            swap(g1[i][j], g1[x][y]);
                            while(x != i || y != j){
                                auto [xx, yy] = pre[x][y];
                                ans.push_back({x, y, xx, yy});
                                x = xx;
                                y = yy;
                            }
                            break;
                        }
                        for(int k = 0; k < 4; k ++){
                            int xx = x + dx[k].x, yy = y + dx[k].y;
                            if(xx < 1 || xx > n || yy < 1 || yy > m || vis[xx][yy] || (PII){xx, yy} < (PII){i, j})continue;
                            pre[xx][yy] = {x, y};
                            vis[xx][yy] = 1;
                            q.push({xx, yy});
                        }
                    }

                }
                
            }
        }
        cout << ans.size() << '\n';
        for(auto v : ans){
            for(auto u : v)cout << u << ' ';
            cout << '\n';
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
    //t = 1;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}
