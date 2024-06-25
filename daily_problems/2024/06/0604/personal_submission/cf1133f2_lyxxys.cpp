#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using Pii = pair<int,int>;
const int N = 200050, mod = 1000001, inf = 1e9;
struct Edge {
    int a, b;
};
vector <int> g[N], d(N), chosen(N);
bool vis[N];
int n, m, aim;

void dfs(int u){
    vis[u] = true;
    for (auto &x : g[u]){
        if (vis[x]) continue;
        dfs(x);
    }
}
void print(){
    queue <int> q;
    q.push(1);
    memset(vis, 0, sizeof vis);
    vis[1] = true;

    while (q.size()){
        int t = q.front();
        q.pop();
        for (auto &x : g[t]){
            if (t == 1 && chosen[x] == 1 || t != 1 && !vis[x]){
                cout << t << " " << x << "\n";
                vis[x] = true;
                q.push(x);
            }
        }
    }
}

void solve(){

    int d1 = 0;
    cin >> n >> m >> aim;
    //先找出1的每个连通块，如果aim小于连通块个数，无解
    //如果aim大于连通块 且 1的度大于等于aim，则可以从连通块中剥离一些边，使得另一端的点和1连通
    for (int i = 1; i <= m; ++ i){
        int a, b;
        cin >> a >> b;
        if (a != 1) g[b].push_back(a);
        if (b != 1) g[a].push_back(b);
        if (a == 1 || b == 1) ++ d1;
    }
    if (aim > d1) return cout << "NO\n", void();
    int cnt = 0;
    for (auto &x : g[1]){
        if (!vis[x]){
            ++ cnt;
            chosen[x] = 1;
            dfs(x);
        }
    }
    if (aim < cnt) return cout << "NO\n", void();
    // cnt <= aim <= d1
    for (auto &x : g[1]){
        if (aim == cnt) break;
        if (!chosen[x]) chosen[x] = 1, ++ cnt;
    }

    cout << "YES\n";
    print();
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
