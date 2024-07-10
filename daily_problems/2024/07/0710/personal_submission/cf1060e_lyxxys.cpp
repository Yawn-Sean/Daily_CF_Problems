#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 200050;

vector <int> g[N];
void solve(){
    int n;
    cin >> n;
    for (int i = 0; i < n-1; ++ i){
        int a, b;
        cin >> a >> b;
        g[a].push_back(b), g[b].push_back(a);
    }
    vector <int> sz(n+1, 1), color(n+1, -1);
    ll odd = 0;
    function<void(int,int)> dfs = [&](int x, int col){
        odd += col;
        color[x] = col;
        for (auto &y : g[x]){
            if (color[y] == -1){
                dfs(y, col^1);
                sz[x] += sz[y];
            }
        }
    };
    dfs(1, 0);
    // 把贡献补上
    ll res = 1ll*odd*(n-odd);
    // 枚举每个点上面的树枝边，下面有sz[i]个点，上面有 n - sz[i]个点
    for (int i = 1; i <= n; ++ i)
        res += 1ll*sz[i]*(n-sz[i]);
    cout << res/2 << "\n";
}
