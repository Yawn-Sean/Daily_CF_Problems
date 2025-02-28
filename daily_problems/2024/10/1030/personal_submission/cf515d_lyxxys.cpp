#include <bits/stdc++.h>
using namespace std;
using ld = long double;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n, m;
    cin >> n >> m;
    vector <string> s(n);
    int all = 0;

    for (int i = 0; i < n; ++ i){
        cin >> s[i];
        for (int j = 0; j < m; ++ j){
            if (s[i][j] == '*') all += 1;
        }
    }

    auto error = [&](){
        cout << "Not unique\n";
    };
    
    const int dx[] = {-1, 0, 1, 0};
    const int dy[] = {0, 1, 0, -1};

    auto chk = [&](int x, int y)->bool{
        return x >= 0 && x < n && y >= 0 && y < m;
    };
    auto ck = [&](int x, int y)->bool{
        if (s[x][y] != '.') return false;
        int c = 0;
        for (int i = 0; i < 4; ++ i){
            int ix = x+dx[i], iy = y+dy[i];
            if (!chk(ix, iy)) continue;
            if (s[ix][iy] == '.') c += 1;
        }
        return c == 1;
    };
    auto find = [&](int x, int y)->int{
        for (int i = 0; i < 4; ++ i){
            int ix = x+dx[i], iy = y+dy[i];
            if (!chk(ix, iy)) continue;
            if (s[ix][iy] == '.') return i;
        }
        assert(0);
    };
    
    auto put = [&](array<int,2>u, array<int,2>v){
        if (u[0] > v[0]) swap(u, v);
        if (u[1] > v[1]) swap(u, v);
        if (u[0] == v[0]){
            s[u[0]][u[1]] = '<';
            s[v[0]][v[1]] = '>';
        } else {
            s[u[0]][u[1]] = '^';
            s[v[0]][v[1]] = 'v'; 
        }
        all += 2;
    };

    auto dfs = [&](auto &&self, int x, int y)->void{
        int idx = find(x, y);
        int tx = x+dx[idx], ty = y+dy[idx];
        put({x,y}, {tx,ty});

        for (int i = 0; i < 4; ++ i){
            int ix = tx+dx[i], iy = ty+dy[i];
            if (!chk(ix, iy)) continue;
            if (ck(ix, iy)){
                self(self, ix, iy);
            }
        }
    };

    for (int i = 0; i < n; ++ i){
        for (int j = 0; j < m; ++ j){
            if (s[i][j] == '.' && ck(i, j)){
                dfs(dfs, i, j);
            }
        }
    }

    if (all != n*m) return error();

    for (int i = 0; i < n; ++ i){
        cout << s[i] << "\n";
    }
}
