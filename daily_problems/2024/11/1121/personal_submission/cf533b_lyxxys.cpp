#include <bits/stdc++.h>
using namespace std;
template <class T> void fmax(T &a, T b){  // 模板类无法处理 long double 问题
    if (b > a) a = b;
}
template <class T> void fmin(T &a, T b){
    if (b < a) a = b;
}

void solve(){
    const long long inf = 1e15;

    int n;
    cin >> n;
    vector <int> A(n), fa(n);
    vector <long long> f0(n), f1(n);
    vector <vector<int>> g(n);
    for (int i = 0; i < n; ++ i){
        cin >> fa[i] >> A[i];
        if (fa[i] > 0){
            fa[i] -= 1;
            g[fa[i]].push_back(i);
        }
    }

    long long res = 0;
    auto dfs = [&](auto &&self, int u)->void{
        f1[u] = -inf;
        for (auto &v : g[u]){
            self(self, v);
            long long x = f0[u], y = f1[u];
            f0[u] = max(x+f0[v], y+f1[v]);
            f1[u] = max(y+f0[v], x+f1[v]);
        }
        f1[u] = max(f1[u], f0[u] + A[u]);
    };
    dfs(dfs, 0);

    cout << max(f0[0], f1[0]) << "\n";
}
