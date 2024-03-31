#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>
#define ctzll(x) __builtin_ctzll(x)
#define popcount(x) __builtin_popcount(x)

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, ans = 0;
    cin >> n;

    vector<int> c(n + 1), to(n + 1), in(n + 1), vis(n + 1);
    for (int i = 1; i <= n; ++i) {
        cin >> c[i];
    }
    for (int i = 1; i <= n; ++i) {
        int x;
        cin >> x;
        to[i] = x; // 建立单向边
        in[x]++; // 入度加一
    }

    queue<int> q;
    for (int i = 1; i <= n; ++i) {
        if (not in[i] and not vis[i]) {
            vis[i] = 1; // 标记访问过
            q.emplace(i); // 准备查找下一个点
        }
    }
    while (q.size()) {
        int u = q.front();
        q.pop();
        if (--in[to[u]] == 0) {
            vis[to[u]] = 1; // 标记访问过
            q.emplace(to[u]); // 准备查找下一个点
        }
    }
    
    function<int(int)> dfs = [&](int x) -> int {
        vis[x] = 1;
        if (not vis[to[x]]) {
            return min(dfs(to[x]), c[x]);
        }
        return c[x];
    };
    
    for (int i = 1; i <= n; ++i) {
        if (not vis[i]) {
            ans += dfs(i);
        }
    }

    cout << ans << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    solve();
    return 0;
}
