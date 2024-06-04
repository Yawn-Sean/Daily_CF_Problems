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
    vector<array<int, 3>> a(n);
    vector<int> g[n], color(n, -1);
    for (array<int, 3> &ai : a) {
        cin >> ai[0] >> ai[1] >> ai[2];
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (pow(a[i][0] - a[j][0], 2) + pow(a[i][1] - a[j][1], 2) == pow(a[i][2] + a[j][2], 2)) {
                g[i].emplace_back(j);
                g[j].emplace_back(i);
            }
        }
    }
    for (int i = 0; i < n; ++i) {
        if (color[i] == -1) {
            color[i] = 0;
            int cnt = 0;
            bool ok = true;
            queue<int> q;
            q.emplace(i);
            while (q.size()) {
                int u = q.front();
                q.pop();
                cnt += (color[u] ? -1 : 1);
                for (int v : g[u]) {
                    if (color[u] == color[v]) {
                        ok = false;
                    } else if (color[v] == -1) {
                        color[v] = color[u] ^ 1;
                        q.emplace(v);
                    }
                }
            }
            if (ok and cnt) {
                cout << "YES";
                return;
            }
        }
    }
    cout << "NO";
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
