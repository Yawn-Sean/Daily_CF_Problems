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
    int n, m;
    cin >> n >> m;
    vector<int> ans(n), step(n, n), cnt(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        ++cnt[u - 1];
        step[u - 1] = min(step[u - 1], (v - u + n) % n);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            int v = (i + j) % n;
            if (cnt[v]) {
                ans[i] = max(ans[i], j + (cnt[v] - 1) * n + step[v]);
            }
        }
    }
    for (int ai : ans) {
        cout << ai << " ";
    }
}

signed main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(15);
    time_t begin = clock();
    solve();
    time_t end = clock();
    double solve_time = double(end - begin) / CLOCKS_PER_SEC;
    // cout << "runtime: " << solve_time << endl;
    return 0;
}
