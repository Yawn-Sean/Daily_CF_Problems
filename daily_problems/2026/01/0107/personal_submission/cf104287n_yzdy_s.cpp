#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
#define LNF 1e18
#define INF 0x3f3f3f3f
#define PII pair<int, int>

int n;
const int maxN = 5e5 + 7;
vector<PII> adj[maxN];
vector<int> dp(maxN);
int aid;
int cnt = 0;
void dfs(int x, int fa) {
    for (auto &[son, w] : adj[x]) {
        if (son == fa) continue;
        dfs(son, x);
    }

    vector<int> vec;
    int mx = -LNF, cx = -LNF;
    for (auto &[son, w] : adj[x]) {
        if (son == fa) continue;
        int val = dp[son] + w;
        if (val >= mx) {
            cx = mx;
            mx = val;
        } else if (val > cx) {
            cx = val;
        }
    }
    if (mx > 0) dp[x] += mx;
    if (dp[x] + cx >= aid || dp[x] >= aid) {
        dp[x] = -LNF;
        cnt++;
    }
}

bool check(int x) {
    for (int i = 1; i <= n; i++) dp[i] = 0;
    cnt = 0;
    aid = x;
    dfs(1, 0);
    if (cnt >= 2) return true;
    return false;
}


void solve(){
    cin >> n;
    for (int i = 1; i <= n; i++) adj[i].clear();
    int r = 0;
    for (int i = 1; i < n; i++) {
        int u, v, w;cin >> u >> v >> w;
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
        r += w;
    }
    r += 7;
    int l = 0;
    int ans = 0;
    while (l <= r) {
        int x = l + r >> 1;
        if (check(x)) {
            l = x + 1;
            ans = x;
        } else r = x - 1;
    }
    cout << ans << endl;
}

signed main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);cout.tie(nullptr);
    int T = 1;cin >> T;
    while (T--) solve();
}