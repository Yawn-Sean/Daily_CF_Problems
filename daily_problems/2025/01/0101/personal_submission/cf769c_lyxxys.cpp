#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
const f64 eps = 1e-9;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}

void solve(){
    int n, m, k;
    cin >> n >> m >> k;

    const int dx[] = {1,0,0,-1}, dy[] = {0,-1,1,0};
    const char towa[] = {'D','L','R','U'};
    auto chk = [&](int x, int y)->bool{
        return x >= 0 && x < n && y >= 0 && y < m;
    };

    int sx = -1, sy = -1;
    vector<vector<int>> g(n,vector<int>(m));
    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            char ch;
            cin >> ch;
            if (ch == 'X') sx = i, sy = j;
            if (ch == '*') g[i][j] = 1;
        }
    }
    bool jg = 1;
    for (int i = 0; i < 4; ++ i){
        int x = sx+dx[i], y = sy+dy[i];
        if (!chk(x, y) || g[x][y]) continue;
        jg = 0;
    }
    if (k%2) jg = 1;

    if (jg){
        cout << "IMPOSSIBLE\n";
        return;
    }

    vector<vector<int>> dist(n,vector<int>(m, -1));
    vector <int> Q(n*m);
    dist[sx][sy] = 0, Q[0] = m * sx + sy;

    int l = 0, r = 1;
    while (l < r){
        auto u = Q[l++];
        int x = u/m, y = u%m;
        for (int i = 0; i < 4; ++ i){
            int ix = x+dx[i], iy = y+dy[i];
            if (!chk(ix, iy) || g[ix][iy] || dist[ix][iy] != -1) continue;
            dist[ix][iy] = dist[x][y] + 1;
            Q[r++] = ix*m + iy;
        }
    }

    string ans;
    while (k){
        for (int i = 0; i < 4; ++ i){
            int ix = sx+dx[i], iy = sy+dy[i];
            if (!chk(ix, iy) || g[ix][iy] || dist[ix][iy] >= k) continue;
            ans += towa[i];
            sx = ix, sy = iy;
            break;
        }
        k -= 1;
    }

    cout << ans << "\n";
}
