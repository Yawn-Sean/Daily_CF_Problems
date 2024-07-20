#include <bits/stdc++.h>
using namespace std;

#define ff first
#define ss second
#define endl '\n'
#define int long long
#define lowbit(x) x & -x
#define PII pair<int, int>
#define PIII pair<int, PII>

const int INF = 0x3f3f3f3f;
const int mod = 1e9 + 7; // 998244353;

void solve() {
    int n, m, cnt1, cnt2, ans = 0;
    bool flag = true;
    cin >> n >> m;
    vector<int> g[n], memo(n, -1);
    while (m--) {
        int u, v;
        string s;
        cin >> u >> v >> s;
        --u, --v;
        if (s == "imposter") {
            g[u].emplace_back(~v);
            g[v].emplace_back(~u);
        } else {
            g[u].emplace_back(v);
            g[v].emplace_back(u);
        }
    }

    function<void(int)> dfs = [&](int u) {
        ++cnt1;
        if (memo[u]) {
            cnt2++;
        }
        for (int &v : g[u]) {
            if (v >= 0) { // 相同阵营
                if (memo[v] == -1) {
                    memo[v] = memo[u];
                    dfs(v);
                } else if (memo[v] != memo[u]) { // 不同阵营，矛盾
                    flag = false;
                }
            } else { // 不同阵营
                v = ~v;
                if (memo[v] == -1) {
                    memo[v] = memo[u] ^ 1;
                    dfs(v);
                } else if (memo[u] == memo[v]) { // 相同阵营，矛盾
                    flag = false;
                }
            }
        }
    };

    for (int i = 0; i < n; ++i) {
        if (memo[i] == -1) {
            cnt1 = cnt2 = 0;
            memo[i] = 0;
            dfs(i);
            ans += max(cnt1 - cnt2, cnt2);
        }
    }
    cout << (flag ? ans : -1) << endl;
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    int Test; cin >> Test; while (Test--)
    solve();
    return 0;
}
