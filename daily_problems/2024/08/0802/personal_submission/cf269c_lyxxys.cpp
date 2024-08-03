#include <bits/stdc++.h>
using namespace std;
using Pii = pair<int,int>;
using ll = long long;
const int N = 200050, mod = 1e9 + 7, inf = 1e9;
struct Edges {
    int to, cap, id, flg;
};
vector <Edges> g[N];
void solve(){
    int n, m;
    cin >> n >> m;
    vector <int> All(n+1), ans(m+1, 1);
    for (int i = 1; i <= m; ++ i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b,c,i,0});
        g[b].push_back({a,c,i,1});
        All[a] += c, All[b] += c;
    }

    for (int i = 1; i <= n; ++ i) All[i] /= 2;

    function<void()> bfs = [&](){
        queue <int> Q;
        vector <int> vis(n+1);
        Q.push(1), vis[1] = true;
        while (!Q.empty()){
            auto t = Q.front();
            Q.pop();
            for (auto &x : g[t]){
                if (vis[x.to]) continue;
                ans[x.id] = x.flg;
                All[x.to] -= x.cap;
                if (All[x.to] == 0 && x.to != n){
                    Q.push(x.to);
                    vis[x.to] = true;
                }
            }
        }
        return;
    };

    bfs();
    for (int i = 1; i <= m; ++ i) cout << ans[i] << "\n";
}
