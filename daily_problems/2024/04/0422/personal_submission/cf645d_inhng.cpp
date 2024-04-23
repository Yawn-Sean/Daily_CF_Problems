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
    vector<PII> lines(m + 1);
    for (int i = 1; i <= m; ++i) {
        cin >> lines[i].ff >> lines[i].ss;
    }

    function<bool(int)> topsort = [&](int mid) -> bool {
        vector<int> g[n + 1], in(n + 1);
        for (int i = 1; i <= mid; ++i) {
            g[lines[i].ff].emplace_back(lines[i].ss);
            in[lines[i].ss]++;
        }
        queue<int> q;
        for (int i = 1; i <= n; ++i) {
            if (not in[i]) {
                q.emplace(i);
            }
        }
        while (q.size() == 1) {
            int u = q.front();
            q.pop();
            for (int v : g[u]) {
                if (--in[v] == 0) {
                    q.emplace(v);
                }
            }
        }
        return q.size() == 0;
    };
    
    int left = 0, right = m + 1;
    while (left + 1 < right) {
        int mid = (left + right) >> 1;
        (topsort(mid) ? right : left) = mid;
    }
    cout << (left < m ? left + 1 : -1);
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
