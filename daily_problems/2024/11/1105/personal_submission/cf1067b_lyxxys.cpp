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

void solve(){
    int n, k;
    cin >> n >> k;
    vector <vector<int>> g(n+1), layer(n+1);
    vector <int> degs(n+1), vis(n+1, -1), dele(n+1);

    for (int i = 0, u,v; i < n-1; ++ i){
        cin >> u >> v;
        degs[u] += 1, degs[v] += 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    for (int i = 1; i <= n; ++ i){
        if (degs[i] == 1){
            layer[0].push_back(i);
            vis[i] = 0;
        }
    }

    bool jg = 1;

    int i;
    // 枚举 i 刺猬点 父节点 的 所有子节点，其中 至少 3 个i-1刺猬的子节点，最多一个未访问的结点
    // 不存在 比 i-1 刺猬点更小的 刺猬点
    for (i = 0; i < n; ++ i){
    
        for (auto &u : layer[i]){
            if (dele[u]) continue;
            int c = 0, fa = -1;
            for (auto &x : g[u]){
                if (vis[x] == -1){
                    fa = x;  // 找到 i+1 刺猬点
                    c += 1;
                }
            }

            if (fa == -1) break;

            if (c > 1) jg = 0;
          
            if (!jg) break;

            vis[fa] = i+1;
            layer[i+1].push_back(fa);

            int c1 = 0, c2 = 0;
            for (auto &x : g[fa]){
                if (vis[x] == -1) c1 += 1;
                else if (vis[x] == vis[fa]-1) c2 += 1;
                else {
                    jg = 0;
                    break;
                }
            }
            if (c2 < 3 || c1 > 1) jg = 0;  // 判断 i+1 刺猬点是否满足条件
            if (!jg) break;

            for (auto &x : g[fa]){
                if (vis[x] == vis[fa]-1){
                    dele[x] = 1;
                }
            }
        }

        if (!jg) break;
        if (!layer[i+1].size()) break;
    }

    if (!jg || i != k){
        cout << "No\n";
    } else cout << "Yes\n";
}
