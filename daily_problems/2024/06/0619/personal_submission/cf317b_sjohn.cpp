#include <bits/stdc++.h>

using namespace std;


using i64 = long long;
using pii = pair<int, int>;
//using u32 = unsigned;
constexpr int inf = INT32_MAX >> 1;
constexpr i64 inf64 = INT64_MAX >> 1;
using vi = vector<int>;
using vl = vector<i64>;
using vb = vector<bool>;
#define all(x) (x).begin(),(x).end()

constexpr int mod = 998244353;
//不能用 dfs stack  或者 bfs queue 模拟  tle
int main() {
    cin.sync_with_stdio(false);
    cout.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, t;
    cin >> n >> t;
    const int M = 200;
    const int base = 100;
    int g[M][M];
    memset(g, 0, sizeof(g));
//    bool vis[M][M];
//    memset(vis, 0, sizeof(vis));
    vector<pii> dirs({{1,  0},
                      {-1, 0},
                      {0,  1},
                      {0,  -1}});
    g[base][base] = n;
    auto dfs=[&](auto &&self,int x,int y){
        int t = g[x+base][y+base];
        if(t<=3) return ;
        int mv = t/4;
        g[x+base][y+base] = t % 4;
        for(auto [dx,dy]:dirs){
            int nx = x + dx, ny = y + dy;
            g[nx+base][ny+base] += mv;
            self(self,nx,ny);
        }
    };
    dfs(dfs,0,0);
    while (t--) {
        int x, y;
        cin >> x >> y;
        if ( x + base >=0 && x + base < M && y + base >=0 && y + base < M)
            cout << g[x + base][y + base] << endl;
        else  cout << 0 << endl;
    }

}
