#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 100550, mod = 998244353, inf = 1e9;
struct Edge {
    int e, dis;
};
vector <Edge> g[N];
int f[N][2];  //f[i][0]点i经过k-1个分支回来的最大价值，f[i][1]点i经过k个分支不回来的最大价值
int n, k;

bool cmp (int i, int j){
    return f[i][0] > f[j][0];
}
void dfs(int x, int fa){
    vector <int> son;
    for (auto &it : g[x]){
        int y = it.e, dis = it.dis;
        if (y == fa) continue;
        son.push_back(y);
        dfs(y, x);
        f[y][0] += dis, f[y][1] += dis;
    }

    int tot = son.size()-1;
    vector <int> pre(tot+1);
    sort(son.begin(), son.end(), cmp);

    for (int i = 0; i <= tot; ++ i)
        pre[i] = (i > 0 ? pre[i-1] : 0) + f[son[i]][0];
    if (k-1 >= 0 && tot >= 0) f[x][0] = pre[min(k-1, tot)];
    for (int i = 0; i <= tot; ++ i){
        int c = son[i];  //枚举每个不回来的儿子
        if (i <= k) f[x][1] = max(f[x][1], pre[min(tot, k)] - f[c][0] + f[c][1]);  
        else f[x][1] = max(f[x][1], (k-1 >= 0 ? pre[k-1] : 0) + f[c][1]);
    }
}

void solve(){

    cin >> n >> k;
    -- k;
    for (int i = 1; i < n; ++ i){
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c}), g[b].push_back({a, c});
    }

    dfs(0, 0);
    cout << f[0][1] << "\n";
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
