#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
const int N = 1e6 + 5;
int fa[N], son[N][2];
int op[N], val[N];
int ans[N], dp[N][2];
int calc(int u) {
    if (op[u] == 1) return val[son[u][0]] & val[son[u][1]];
    if (op[u] == 2) return val[son[u][0]] | val[son[u][1]];
    if (op[u] == 3) return val[son[u][0]] ^ val[son[u][1]];
    if (op[u] == 4) return !val[son[u][0]];
}
void dfs1(int u) {
    if (u == 0 || op[u] == 0) return;
    dfs1(son[u][0]);
    dfs1(son[u][1]);
    val[u] = calc(u);
}
void dfs2(int u) {
    if (u == 0) return;
    int tmp = val[u];
    if (u != 1) {
        val[u] = 0;
        dp[u][0] = dp[fa[u]][calc(fa[u])];
        val[u] = 1;
        dp[u][1] = dp[fa[u]][calc(fa[u])];
    }
    val[u] = tmp;
    dfs2(son[u][0]);
    dfs2(son[u][1]);
    if (op[u] == 0) {
        ans[u] = dp[u][!tmp];
    }
}
void solve() {
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++) {
        string s;
        cin >> s;
        if (s[0] == 'A') op[i] = 1;
        if (s[0] == 'O') op[i] = 2;
        if (s[0] == 'X') op[i] = 3;
        if (s[0] == 'I' || s[0] == 'N') {
            int x;
            cin >> x;
            if (s[0] == 'N') {
                op[i] = 4;
                son[i][0] = x;
                fa[x] = i;
            } else {
                val[i] = x;
            }
        } else {
            int x, y;
            cin >> x >> y;
            son[i][0] = x;
            son[i][1] = y;
            fa[x] = fa[y] = i;
        }
    }
    dfs1(1);
    dp[1][0] = 0, dp[1][1] = 1;
    dfs2(1);
    for (int i = 1; i <= n; i++) {
        if (op[i] == 0) cout << ans[i];
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int T = 1;
    while (T--) {
        solve();
    }
    return 0;
}