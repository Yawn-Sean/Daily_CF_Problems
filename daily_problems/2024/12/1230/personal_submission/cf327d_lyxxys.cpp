#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}

void solve(){
    using ary3 = array<int,3>;

    int n, m;
    cin >> n >> m;
    vector<vector<int>> vis(n, vector<int>(m));
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            char x;
            cin >> x;
            if (x == '#') vis[i][j] = 1;
        }
    }

    vector <ary3> ans;
    const int dx[] = {-1,0,1,0,-1};
    auto chk = [&](int x, int y)->bool{
        return x >= 0 && x < n && y >= 0 && y < m;
    };
    auto bfs = [&](int sx, int sy)->void{
        vector <array<int,2>> loc = {{sx, sy}};
        queue <array<int,2>> Q;
        vis[sx][sy] = 1, Q.push({sx, sy});
        while (!Q.empty()){
            auto u = Q.front();
            Q.pop();
            for (int i = 0; i < 4; ++ i){
                int ix = u[0]+dx[i], iy = u[1]+dx[i+1];
                if (!chk(ix, iy) || vis[ix][iy]) continue;
                vis[ix][iy] = 1;
                Q.push({ix, iy});
                loc.push_back({ix, iy});
            }
        }

        int L = loc.size();
        for (auto &it : loc) ans.push_back({0, it[0]+1, it[1]+1});
        for (int i = L-1; i > 0; -- i){
            auto &it = loc[i];
            ans.push_back({2, it[0]+1, it[1]+1});
            ans.push_back({1, it[0]+1, it[1]+1});
        }
    };

    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (!vis[i][j]){
                bfs(i, j);
            }
        }
    }

    int ans_l = ans.size();
    cout << ans_l << "\n";
    for (int i = 0; i < ans_l; ++ i){
        int opt = ans[i][0];
        if (opt == 0) cout << 'B';
        else if (opt == 1) cout << 'R';
        else cout << "D";

        cout << " " << ans[i][1] << " " << ans[i][2] << "\n";
    }
}
