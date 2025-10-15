#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}
struct dsu {
    vector <int> p, sz, add;
    dsu(){}
    dsu(int n): p(n+1), sz(n+1, 1){
        iota(p.begin(), p.end(), 0);
    }
    bool same(int x, int y){
        return root(x) == root(y);
    }
    int root(int x){
        return p[x] = x==p[x] ? x : root(p[x]);
    }
    int size(int x){
        return sz[root(x)];
    }
    void merge(int x, int y){
        x = root(x), y = root(y);
        if (x == y) return;
        if (size(x) < size(y)) swap(x, y);
        sz[x] += sz[y], p[y] = x;
    }
};

void solve(){
    auto error = [&]()->void{
        cout << "NO\n";
    };
    long long k;
    int n, m;
    cin >> n >> m >> k;

    auto id = [&](int x, int y)->int{
        return (x-1)*m + y;
    };
    
    vector <vector<int>> A(n+1, vector<int>(m+1));
    vector <array<int,2>> order;
    for (int i = 1; i <= n; ++ i){
        for (int j = 1; j <= m; ++ j){
            cin >> A[i][j];
            order.push_back({i, j});
        }
    }

    sort(order.begin(), order.end(), [&](array<int,2>&u, array<int,2>&v){
        return A[u[0]][u[1]] > A[v[0]][v[1]];
    });

    auto ck_dir = [&](int x, int y)->bool{
        return x >= 1 && x <= n && y >= 1 && y <= m;
    };
    const int dx[] = {-1, 0, 1, 0};
    const int dy[] = {0, 1, 0, -1};

    dsu uni(n*m);
    for (auto &it : order){
        int x = it[0], y = it[1];
        for (int i = 0; i < 4; ++ i){
            int ix = x+dx[i], iy = y+dy[i];
            if (!ck_dir(ix, iy) || A[ix][iy] < A[x][y]) continue;
            uni.merge(id(x,y), id(ix,iy));
        }

        int cur = A[x][y];
        if (k%cur == 0 && uni.size(id(x,y)) >= k/cur){
            int all = k/cur;
            vector <vector<int>> vis(n+1, vector<int>(m+1));

            auto dfs = [&](auto &&self, int x, int y)->void{
                if (!all) return;
                all -= 1;
                vis[x][y] = 1;
                for (int i = 0; i < 4; ++ i){
                    int ix = x+dx[i], iy = y+dy[i];
                    if (!ck_dir(ix, iy) || vis[ix][iy]) continue;
                    if (A[ix][iy] < cur) continue;
                    self(self, ix, iy);
                }
            };

            dfs(dfs, x, y);
            cout << "YES\n";
            for (int i = 1; i <= n; ++ i){
                for (int j = 1; j <= m; ++ j){
                    if (j > 1) cout << " ";
                    cout << (vis[i][j] ? cur : 0);
                }
                cout << "\n";
            }
            return;
        }
    }

    return error();
}
