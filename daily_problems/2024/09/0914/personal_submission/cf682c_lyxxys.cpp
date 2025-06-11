#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int mod = 1e9+7;
struct Edge {
    int to;
    long long len;
};
void solve(){
    int n;
    cin >> n;
    vector <vector<Edge>> g(n+1);
    vector <int> w(n+1), del(n+1);
    for (int i = 1; i <= n; ++ i) cin >> w[i];

    for (int i = 2,p,c; i <= n; ++ i){
        cin >> p >> c;
        g[p].push_back({i, c});
    }

    function<void(int,long long)> dfs = [&](int x, long long dis){
        if (dis > w[x]){
            del[x] = 1;
            return;
        }
        for (auto &it : g[x]){
            dfs(it.to, max(it.len, it.len+dis));
        }
    };
    dfs(1, -1e18);
 
    function<void(int)> dele_son = [&](int x){
        del[x] = 1;
        for (auto &it : g[x]){
            if (del[it.to]) continue;
            dele_son(it.to);
        }
    };
    for (int i = 1; i <= n; ++ i){
        if (del[i]){
            dele_son(i);
        }
    }

    int res = 0;
    for (int i = 1; i <= n; ++ i)
        if (del[i]) ++ res;
    cout << res << "\n";
}
 
