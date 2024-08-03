#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pii = pair<int,int>;
const int N = 1050, mod = 1000001, inf = 1e9;
struct Circle {
    ll x, y, r;
};
int vis[N], ct1, ct2;
vector <int> g[N];

void dfs(int p, int col, int &f){
    if (vis[p] != -1) return f &= (col == vis[p]), void();
    (vis[p]=col) ? ++ ct2 : ++ ct1;
    for (auto &x : g[p])
        dfs(x, !col, f);
}

void solve(){
    int n; 
    cin >> n;
    vector <Circle> p(n+1);
    for (int i = 1; i <= n; ++ i) cin >> p[i].x >> p[i].y >> p[i].r;
    auto check = [&](Circle &a, Circle &b){
        ll d = (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y);
        return d == (a.r+b.r)*(a.r+b.r);
    };
    for (int i = 1; i <= n; ++ i)
        for (int j = 1; j < i; ++ j)
            if (check(p[i], p[j])){
                g[i].push_back(j);
                g[j].push_back(i);
            }
    memset(vis, -1, sizeof vis);
    for (int i = 1, f; i <= n; ++ i)
        if (vis[i] == -1){
            ct1 = ct2 = 0, f = 1;
            dfs(i, 0, f);
            if (f && ct1 != ct2) return cout << "YES\n", void();
        }
    cout << "NO\n";
}

int main(){
#ifdef ONLINE_JUDGE
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#else
    freopen("in.txt", "rt", stdin), freopen("out.txt", "wt", stdout);
#endif
    int _ = 1;
    while (_--) solve();
    return 0;
}
