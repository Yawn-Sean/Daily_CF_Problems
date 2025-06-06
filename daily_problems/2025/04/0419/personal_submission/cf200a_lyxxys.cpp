#pragma GCC optimize(2)
#pragma GCC optimize(3)

#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
using f64 = long double;
using u64 = unsigned long long;
const f64 eps = 1e-12;
const i64 inf_i64 = 1e18;
const int inf_int = 1e9;
template <class T> void fmax(T &a, const T &b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, const T &b){
    if (b < a) a = b;
}
template <class T> void print(vector <T> &A, int d = 0){
    int n = A.size();
    for (int i = 0; i < n; ++ i){
        if (i) cout << " ";
        cout << A[i]+d;
    }
    cout << "\n";
}
int jgs(f64 x){
    return x < -eps ? -1 : x > eps;
}

void solve(){
    const int N = 2002;
    int n, m, k;
    cin >> n >> m >> k;
    const int d = sqrt(k)+1;
    static int p[4][N][N], vis[N][N];  // 0123，左右上下

    for (int u = 0; u < 4; ++ u){
        for (int i = 0; i <= n+1; ++ i){
            for (int j = 0; j <= m+1; ++ j){
                if (u < 2){
                    p[u][i][j] = j;
                } else {
                    p[u][i][j] = i;
                }
            }
        }
    }
    // 找到每一个连通块左右上下的代表点
    auto root = [&](auto &&self, int u, int i, int j)->int{
        if (u < 2 && p[u][i][j] == j || u >= 2 && p[u][i][j] == i) return p[u][i][j];
        if (u < 2){
            return p[u][i][j] = self(self, u, i, p[u][i][j]);
        } else {
            return p[u][i][j] = self(self, u, p[u][i][j], j);
        }
    };
    auto extend = [&](int x, int y)->void{
        if (vis[x][y-1]){
            int l = root(root, 0, x, y-1);
            p[0][x][y] = l;
            p[1][x][y-1] = y;
        }
        if (vis[x][y+1]){
            int r = root(root, 1, x, y+1);
            p[1][x][y] = r;
            p[0][x][y+1] = y;
        }
        if (vis[x-1][y]){
            int up = root(root, 2, x-1, y);
            p[2][x][y] = up;
            p[3][x-1][y] = x;
        }
        if (vis[x+1][y]){
            int low = root(root, 3, x+1, y);
            p[3][x][y] = low;
            p[2][x+1][y] = x;
        }
    };

    vector <array<int,2>> ans;
    for (int i = 0; i < k; ++ i){
        int x, y;
        cin >> x >> y;
        if (!vis[x][y]){

            vis[x][y] = 1;
            ans.push_back({x, y});
            extend(x, y);
            continue;
        }

        int ux = inf_int, uy = inf_int;
        auto better = [&](int ix, int iy)->void{
            if (abs(ix-x)+abs(iy-y) < abs(ux-x)+abs(uy-y)){
                ux = ix, uy = iy;
            } else if (abs(ix-x)+abs(iy-y) == abs(ux-x)+abs(uy-y) && (ix < ux || ix==ux && iy < uy)){
                ux = ix, uy = iy;
            }
        };
        // 枚举竖着的列对角线
        for (int u = max(x-d, 1); u <= min(x+d, n); ++ u){
            if (!vis[u][y]){
                better(u, y);
            } else {
                int l = root(root, 0, u, y), r = root(root, 1, u, y);
                l -= 1, r += 1;
                if (l >= 1) better(u, l);
                if (r <= m) better(u, r);
            } 
        }
        // 枚举横着的行对角线
        for (int u = max(y-d, 1); u <= min(y+d, m); ++ u){
            if (!vis[x][u]){
                better(x, u);
            } else {
                int up = root(root, 2, x, u), low = root(root, 3, x, u);
                up -= 1, low += 1;
                if (up >= 1) better(up, u);
                if (low <= n) better(low, u);
            }
        }

        assert(ux >= 1 && ux <= n && uy >= 1 && uy <= m);
        assert(!vis[ux][uy]);

        ans.push_back({ux, uy});
        vis[ux][uy] = 1;
        extend(ux, uy);
    }

    // return;
    for (auto &[x, y] : ans){
        cout << x << " " << y << "\n";
    }
}


int main(){
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
#else
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int _ = 1;
    while (_--){
        solve();
    }
    return 0;
}
