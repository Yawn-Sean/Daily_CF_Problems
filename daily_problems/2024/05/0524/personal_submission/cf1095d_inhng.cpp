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
    int n;
    cin >> n;
    vector g(n + 1, vector<int>(2));
    for (int i = 1; i <= n; ++i) {
        cin >> g[i][0] >> g[i][1];
    }

    function<bool(int, int)> check = [&](int u, int v) -> bool {
        vector<int> ans;
        for (int i = 0; i < n; ++i) {
            if (g[u][0] == v) {
                ans.emplace_back(g[u][1]);
            } else if (g[u][1] == v) {
                ans.emplace_back(g[u][0]);
            } else {
                return false;
            }
            u = v;
            v = ans.back();
        }
        for (int ai : ans) {
            cout << ai << " \n"[ai == ans.back()];
        }
        return true;
    };
    
    for (int i = 0; i < 2; ++i) {
        if (check(1, g[1][i])) {
            return;
        }
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
