#include <iostream>       
#include <vector>
#include <numeric>
using namespace std;      
#define PII pair<int, int>
#define f first           
#define s second
#define int long long
const int N = 1e5 + 10, mod = 1e9 + 7;

vector<int> ed[N];
vector<PII> edg;
int fa[N], dep[N], dth[N], fat[N][20];
int sum[N];

int find(int x) {
    if (x == fa[x]) return x;
    return fa[x] = find(fa[x]);
}

void dfs(int u, int f) {
    for (int v : ed[u]) if (v != f) {
        fa[v] = u;
        dep[v] = dep[u] + 1;
        dfs(v, u);
    }
}

void dfs1(int u, int f) {
    int dv = dth[u], du = dth[f];
    if (dv != du) {
        fat[dv][0] = du;
        dep[dv] = dep[du] + 1;
        sum[dv] = sum[du] + (dv <= (int)edg.size());
        for (int i = 1; i < 20; i++) {
            fat[dv][i] = fat[fat[dv][i - 1]][i - 1];
        }
    }
    for (int v : ed[u]) if (v != f) dfs1(v, u);
}

int lca(int v, int u) {
    for (int i = 19; i >= 0; i--) {
        if (dep[fat[u][i]] >= dep[v]) {
            u = fat[u][i];
        }
    }
    if (u == v) return v;
    for (int i = 19; i >= 0; i--) {
        if (fat[u][i] != fat[v][i]) {
            u = fat[u][i];
            v = fat[v][i];
        }
    }
    return fat[u][0] == 0 ? dth[1] : fat[u][0];
}

int qmi(int a, int b) {
    int ret = 1;
    while (b) {
        if (b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

void yrlpSolve() {
    int n, m; cin >> n >> m;
    iota(fa, fa + N, 0);
    for (int i = 0; i < m; i++) {
        int u, v; cin >> u >> v;
        if (find(u) == find(v)) edg.emplace_back(u, v);
        else {
            ed[u].emplace_back(v);
            ed[v].emplace_back(u);
            fa[find(u)] = find(v);
        }
    }
    int t = 1; // 环的编号，从1开始
    dfs(1, 0); // 建树
    for (auto &p : edg) {
        int u = p.f, v = p.s;
        if (dep[u] < dep[v]) swap(u, v);
        while (dep[u] > dep[v]) dth[u] = t, u = fa[u];  // i号点所在环的编号是dth[i]
        while (u != v) dth[u] = dth[v] = t, u = fa[u], v = fa[v];
        dth[u] = t++;
    }
    for (int i = 1; i <= n; i++) if (!dth[i]) dth[i] = t++; // !dth[i]说明这个点没在环里，它们的t都会大于edg.size()

    // 初始化lca要用的fat数组和dep数组(这里的dep[i]往后就是i号环的深度）
    //同时初始化sum[i]，sum[i]:i号环到根节点的路径上环编号小于等于edg.size()的个数
    dfs1(1, 0);

    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int u, v; cin >> u >> v;
        u = dth[u], v = dth[v];
        if (dep[u] < dep[v]) swap(v, u);
        int g = lca(v, u);
        int h = sum[u] - sum[fat[g][0]] + sum[v] - sum[g];
        cout << qmi(2, h) << endl;
    }
}

signed main() {
    int T = 1; //cin >> T;
    while (T--) yrlpSolve();
}
