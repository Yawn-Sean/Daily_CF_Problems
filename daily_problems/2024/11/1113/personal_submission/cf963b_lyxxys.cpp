#include <bits/stdc++.h>
using namespace std;
const long double Pi = acos(-1.0);
template <class T> void fmax(T &a, T b){
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> g(n);

    for (int i = 0,p; i < n; ++ i){
        cin >> p;
        if (!p) continue;
        p -= 1;
        g[p].push_back(i), g[i].push_back(p);

    }

    int rt = 0;

    vector <int> f(n), ans;
    vector <vector<int>> tmps(n);
    auto find = [&](auto &&self, int x, int fa)->void{  // 找有偶数个儿子未删除的
        if (tmps[x].size()%2) return;
        f[x] = 1;
        ans.push_back(x);
        for (auto &y : tmps[x]){
            self(self, y, x);
        }
    };
    auto dfs = [&](auto &&self, int x, int fa)->void{
        for (auto &y : g[x]){
            if (y == fa) continue;
            self(self, y, x);
            if (!f[y]) tmps[x].push_back(y);
        }

        if (tmps[x].size()%2){
            f[x] = 1;
            ans.push_back(x);
            for (auto &j : tmps[x]){
                find(find, j, x);
            }
        }
    };

    for (auto &y : g[rt]){
        dfs(dfs, y, rt);
        if (!f[y]){
            tmps[rt].push_back(y);
        }
    }
    find(find, rt, -1);

    assert(ans.size() <= n);
    if (ans.size() != n){
        cout << "NO\n";
    } else {
        cout << "YES\n";
        for (auto &x : ans){
            cout << x+1 << "\n";
        }
    }
}

